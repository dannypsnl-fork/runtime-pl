//
// Created by dannypsnl on 2020/1/24.
//

#ifndef SYNTHESIZING_SRC_INSTRUCTION_H_
#define SYNTHESIZING_SRC_INSTRUCTION_H_

#include <cstdint>

typedef uint32_t ID;

class Operator {};

struct Instruction {
  ID id;
  Operator op;
  Instruction(ID id, Operator op);
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

struct Var : public Operator {};
struct Const : public Operator {
  uint64_t value;
  explicit Const(uint64_t value) : value{value} {}
};
struct EqualZero : public Operator {
  ID operand;
  explicit EqualZero(ID ope) : operand{ope} {}
};
#define BinaryOperatorStruct(NAME)                         \
  struct NAME : public Operator {                          \
    ID operand1, operand2;                                 \
    NAME(ID op1, ID op2) : operand1{op1}, operand2{op2} {} \
  }
BinaryOperatorStruct(Equal);
BinaryOperatorStruct(NotEqual);
BinaryOperatorStruct(LessThan);
BinaryOperatorStruct(LessEqual);
BinaryOperatorStruct(GreaterThen);
BinaryOperatorStruct(GreaterEqual);
BinaryOperatorStruct(Add);
BinaryOperatorStruct(Sub);
BinaryOperatorStruct(Mul);
BinaryOperatorStruct(Div);
struct Select : public Operator {
  ID operand1, operand2, operand3;
  Select(ID op1, ID op2, ID op3)
      : operand1{op1}, operand2{op2}, operand3{op3} {}
};

#endif  // SYNTHESIZING_SRC_INSTRUCTION_H_
