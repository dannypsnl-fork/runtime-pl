//
// Created by dannypsnl on 2020/1/25.
//

#ifndef SYNTHESIZING_SRC_COMPONENT_H_
#define SYNTHESIZING_SRC_COMPONENT_H_

#include <optional>
#include <vector>
#include "Instruction.h"
#include "z3.h"

template <unsigned int operand>
struct Component {
  /// How many operands does this component take?
  unsigned int operand_arity() { return operand; }
  /// How many immediates does this component need
  /// synthesized?
  virtual unsigned int immediate_arity() = 0;
  /// Construct this component's constraint as a Z3
  /// expression.
  virtual Z3_ast make_expression(Z3_context ctx, std::vector<Z3_ast> immediates,
                                 std::vector<Z3_ast> operands,
                                 uint32_t bit_width) = 0;
  /// Construct an `Operator` from the given
  /// immediates and operands.
  virtual Operator make_operator(std::vector<uint64_t> immediates,
                                 std::vector<ID> operands) = 0;
};

struct CConst : public Component<0> {
  std::optional<uint64_t> value;
  unsigned int immediate_arity() override;
  Z3_ast make_expression(Z3_context ctx, std::vector<Z3_ast> immediates,
                         std::vector<Z3_ast> operands,
                         uint32_t bit_width) override;
  Operator make_operator(std::vector<uint64_t> immediates,
                         std::vector<ID> operands) override;
};

#define ComponentStruct(NAME, OPERAND)                                     \
  struct C##NAME : public Component<OPERAND> {                             \
    unsigned int immediate_arity() override;                               \
    Z3_ast make_expression(Z3_context ctx, std::vector<Z3_ast> immediates, \
                           std::vector<Z3_ast> operands,                   \
                           uint32_t bit_width) override;                   \
    Operator make_operator(std::vector<uint64_t> immediates,               \
                           std::vector<ID> operands) override;             \
  }

ComponentStruct(Equal, 2);
ComponentStruct(NotEqual, 2);
ComponentStruct(LessThan, 2);
ComponentStruct(LessEqual, 2);
ComponentStruct(GreaterThen, 2);
ComponentStruct(GreaterEqual, 2);
ComponentStruct(Add, 2);
ComponentStruct(Sub, 2);
ComponentStruct(Mul, 2);
ComponentStruct(Div, 2);

// TODO: EqualZero
// TODO: Select

#endif  // SYNTHESIZING_SRC_COMPONENT_H_
