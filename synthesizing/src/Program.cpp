//
// Created by dannypsnl on 2020/1/24.
//

#include "Program.h"
#include "Instruction.h"

unsigned int Program::arity() {
  unsigned int count{0};
  for (auto inst : this->instructions) {
    if (typeid(inst.op) == typeid(Var)) {
      count++;
    }
  }
  return count;
}
Z3_bool Program::make_expression(Z3_context ctx, std::vector<Z3_ast> inputs,
                                 Z3_ast output, uint32_t bit_width) {
  std::vector<Z3_ast> exprs = inputs;
  for (auto i = exprs.size(); i < this->instructions.size(); ++i) {
    std::vector<Z3_ast> immediates{};
    std::vector<Z3_ast> operands{};
    auto inst = this->instructions[i];
    inst.op->operands(
        [&operands, exprs](ID id) { operands.push_back(exprs[id]); });
    exprs.push_back(
        inst.op->make_expression(ctx, immediates, operands, bit_width));
  }
  auto last = exprs.back();
  return Z3_mk_eq(ctx, last, output);
}
