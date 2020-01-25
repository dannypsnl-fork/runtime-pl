//
// Created by dannypsnl on 2020/1/25.
//

#include "Component.h"

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
Operator CConst::make_operator(std::vector<uint64_t> immediates,
                               std::vector<ID> operands) {
  if (this->value) {
    return Const(this->value.value());
  } else {
    return Const(immediates[0]);
  }
}

#define BinaryComponent(NAME, Z3_FUNC)                              \
  unsigned int C##NAME::immediate_arity() { return 0; }             \
  Z3_ast C##NAME::make_expression(                                  \
      Z3_context ctx, std::vector<Z3_ast> immediates,               \
      std::vector<Z3_ast> operands, uint32_t bit_width) {           \
    return Z3_mk_##Z3_FUNC(ctx, operands[0], operands[1]);          \
  }                                                                 \
  Operator C##NAME::make_operator(std::vector<uint64_t> immediates, \
                                  std::vector<ID> operands) {       \
    return NAME(operands[0], operands[1]);                          \
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
