//
// Created by dannypsnl on 2020/1/24.
//

#include "Instruction.h"

Instruction::Instruction(ID id, std::shared_ptr<Operator> op)
    : id{id}, op{op} {}

Instruction Instruction::var(ID self_id) {
  return Instruction(self_id, std::make_shared<Var>(Var()));
}
Instruction Instruction::const_(ID self_id, uint64_t value) {
  return Instruction(self_id, std::make_shared<Const>(Const(value)));
}
Instruction Instruction::equal_zero(ID self_id, ID op1) {
  return Instruction(self_id, std::make_shared<EqualZero>(EqualZero(op1)));
}
Instruction Instruction::equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<Equal>(Equal(op1, op2)));
}
Instruction Instruction::not_equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<NotEqual>(NotEqual(op1, op2)));
}
Instruction Instruction::less_than(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<LessThan>(LessThan(op1, op2)));
}
Instruction Instruction::less_equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<LessEqual>(LessEqual(op1, op2)));
}
Instruction Instruction::greater_then(ID self_id, ID op1, ID op2) {
  return Instruction(self_id,
                     std::make_shared<GreaterThen>(GreaterThen(op1, op2)));
}
Instruction Instruction::greater_equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id,
                     std::make_shared<GreaterEqual>(GreaterEqual(op1, op2)));
}
Instruction Instruction::add(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<Add>(Add(op1, op2)));
}
Instruction Instruction::sub(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<Sub>(Sub(op1, op2)));
}
Instruction Instruction::mul(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<Mul>(Mul(op1, op2)));
}
Instruction Instruction::div(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, std::make_shared<Div>(Div(op1, op2)));
}
Instruction Instruction::select(ID self_id, ID op1, ID op2, ID op3) {
  return Instruction(self_id, std::make_shared<Select>(Select(op1, op2, op3)));
}

unsigned int CConst::immediate_arity() {
  if (this->value) {
    return 0;
  } else {
    return 1;
  }
}
Z3_ast CConst::make_expression(Z3_context ctx, std::vector<Z3_ast> immediates,
                               std::vector<Z3_ast> operands,
                               uint32_t bit_width) {
  if (this->value) {
    Z3_sort sort = Z3_mk_bv_sort(ctx, bit_width);
    return Z3_mk_int64(ctx, this->value.value(), sort);
  } else {
    return immediates[0];
  }
}
std::shared_ptr<Operator> CConst::make_operator(
    std::vector<uint64_t> immediates, std::vector<ID> operands) {
  if (this->value) {
    return std::make_shared<Const>(Const(this->value.value()));
  } else {
    return std::make_shared<Const>(Const(immediates[0]));
  }
}

// implements Component
#define BinaryComponent(NAME, Z3_FUNC)                                         \
  unsigned int NAME::immediate_arity() { return 0; }                           \
  Z3_ast NAME::make_expression(Z3_context ctx, std::vector<Z3_ast> immediates, \
                               std::vector<Z3_ast> operands,                   \
                               uint32_t bit_width) {                           \
    return Z3_mk_##Z3_FUNC(ctx, operands[0], operands[1]);                     \
  }                                                                            \
  std::shared_ptr<Operator> NAME::make_operator(                               \
      std::vector<uint64_t> immediates, std::vector<ID> operands) {            \
    return std::make_shared<NAME>(NAME(operands[0], operands[1]));             \
  }

BinaryComponent(Equal, eq);
// FIXME: not equal is reversed equal, haven't done
// refer to how Rust version could do(ite => if then else):
// eq
// operands[0]
//._eq(&operands[1])
//.ite(&one(context, bit_width), &zero(context, bit_width))
// ne
// operands[0]
//._eq(&operands[1])
//.ite(&zero(context, bit_width), &one(context, bit_width))
BinaryComponent(NotEqual, eq);
BinaryComponent(LessThan, bvslt);
BinaryComponent(LessEqual, bvsle);
BinaryComponent(GreaterThen, bvsgt);
BinaryComponent(GreaterEqual, bvsge);
BinaryComponent(Add, bvadd);
BinaryComponent(Sub, bvsub);
BinaryComponent(Mul, bvmul);
BinaryComponent(Div, bvsdiv);
