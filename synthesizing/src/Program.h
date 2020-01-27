//
// Created by dannypsnl on 2020/1/24.
//

#ifndef SYNTHESIZING_SRC_PROGRAM_H_
#define SYNTHESIZING_SRC_PROGRAM_H_

#include <vector>
#include "Instruction.h"
#include "Specification.h"

struct Program : public Specification {
  std::vector<Instruction> instructions;

  explicit Program() : instructions{} {}
  // implements Specification
  unsigned int arity() override;
  Z3_bool make_expression(Z3_context context, std::vector<Z3_ast> inputs,
                          Z3_ast output, uint32_t bit_width) override;
};

#endif  // SYNTHESIZING_SRC_PROGRAM_H_
