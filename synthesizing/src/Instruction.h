//
// Created by dannypsnl on 2020/1/24.
//

#ifndef SYNTHESIZING_SRC_INSTRUCTION_H_
#define SYNTHESIZING_SRC_INSTRUCTION_H_

#include <array>
#include <cstdint>
#include <functional>
#include <memory>
#include "Component.h"
#include "z3.h"

class Operator : public Component {
 public:
  virtual void operands(std::function<void(ID)> f) = 0;
};

struct Instruction {
  ID id;
  std::shared_ptr<Operator> op;
  Instruction(ID id, std::shared_ptr<Operator> op);
  static Instruction var(ID self_id);
  static Instruction const_(ID self_id, uint64_t value);
  static Instruction equal_zero(ID self_id, ID op1);
  static Instruction equal(ID self_id, ID op1, ID op2);
  static Instruction not_equal(ID self_id, ID op1, ID op2);
  static Instruction less_than(ID self_id, ID op1, ID op2);
  static Instruction less_equal(ID self_id, ID op1, ID op2);
  static Instruction greater_then(ID self_id, ID op1, ID op2);
  static Instruction greater_equal(ID self_id, ID op1, ID op2);
  static Instruction add(ID self_id, ID op1, ID op2);
  static Instruction sub(ID self_id, ID op1, ID op2);
  static Instruction mul(ID self_id, ID op1, ID op2);
  static Instruction div(ID self_id, ID op1, ID op2);
  static Instruction select(ID self_id, ID op1, ID op2, ID op3);
};

template <uint8_t operands_amount>
class OperandsPolicy : public Operator {
 protected:
  // `0` can be value of `operands_amount`
  std::array<ID, operands_amount> _operands;

 public:
  // implements Operator
  void operands(std::function<void(ID)> f) override {
    for (uint8_t i = 0; i < operands_amount; ++i) {
      f(this->_operands[i]);
    }
  }
  // implements Component
  unsigned int operand_arity() final { return operands_amount; }
  unsigned int immediate_arity() override { return 0; }
  Z3_ast make_expression(Z3_context ctx, std::vector<Z3_ast> immediates,
                         std::vector<Z3_ast> operands,
                         uint32_t bit_width) override {
    return nullptr;
  }
  std::shared_ptr<Operator> make_operator(std::vector<uint64_t> immediates,
                                          std::vector<ID> operands) override {
    return nullptr;
  }
};

struct Var : public OperandsPolicy<0> {};

struct CConst : public OperandsPolicy<0> {
  std::optional<uint64_t> value;
  unsigned int immediate_arity() override;
  Z3_ast make_expression(Z3_context ctx, std::vector<Z3_ast> immediates,
                         std::vector<Z3_ast> operands,
                         uint32_t bit_width) override;
  std::shared_ptr<Operator> make_operator(std::vector<uint64_t> immediates,
                                          std::vector<ID> operands) override;
};

struct Const : public CConst {
  uint64_t value;
  explicit Const(uint64_t value) : value{value} {}
};
// FIXME: component
struct EqualZero : public OperandsPolicy<1> {
  explicit EqualZero(ID ope) { _operands = {ope}; }
};
#define BinaryOperatorStruct(NAME, OPERAND)                                   \
  struct NAME : public OperandsPolicy<OPERAND> {                              \
    NAME(ID op1, ID op2) { _operands = {op1, op2}; }                          \
    unsigned int immediate_arity() override;                                  \
    Z3_ast make_expression(Z3_context ctx, std::vector<Z3_ast> immediates,    \
                           std::vector<Z3_ast> operands,                      \
                           uint32_t bit_width) override;                      \
    std::shared_ptr<Operator> make_operator(                                  \
        std::vector<uint64_t> immediates, std::vector<ID> operands) override; \
  }
BinaryOperatorStruct(Equal, 2);
BinaryOperatorStruct(NotEqual, 2);
BinaryOperatorStruct(LessThan, 2);
BinaryOperatorStruct(LessEqual, 2);
BinaryOperatorStruct(GreaterThen, 2);
BinaryOperatorStruct(GreaterEqual, 2);
BinaryOperatorStruct(Add, 2);
BinaryOperatorStruct(Sub, 2);
BinaryOperatorStruct(Mul, 2);
BinaryOperatorStruct(Div, 2);
// FIXME: component
struct Select : public OperandsPolicy<3> {
  Select(ID op1, ID op2, ID op3) { _operands = {op1, op2, op3}; }
};

#endif  // SYNTHESIZING_SRC_INSTRUCTION_H_
