//
// Created by dannypsnl on 2020/1/24.
//

#ifndef SYNTHESIZING_SRC_INSTRUCTION_H_
#define SYNTHESIZING_SRC_INSTRUCTION_H_

#include <cstdint>

typedef uint32_t ID;

struct Instruction {
  ID id;
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

struct Var : public Instruction {};
struct Const : public Instruction {
  uint64_t value;
};
struct EqualZero : public Instruction {
  ID operand;
};
struct Equal : public Instruction {
  ID operand1, operand2;
};
struct NotEqual : public Instruction {
  ID operand1, operand2;
};
struct LessThan : public Instruction {
  ID operand1, operand2;
};
struct LessEqual : public Instruction {
  ID operand1, operand2;
};
struct GreaterThen : public Instruction {
  ID operand1, operand2;
};
struct GreaterEqual : public Instruction {
  ID operand1, operand2;
};
struct Add : public Instruction {
  ID operand1, operand2;
};
struct Sub : public Instruction {
  ID operand1, operand2;
};
struct Mul : public Instruction {
  ID operand1, operand2;
};
struct Div : public Instruction {
  ID operand1, operand2;
};
struct Select : public Instruction {
  ID operand1, operand2, operand3;
};

#endif // SYNTHESIZING_SRC_INSTRUCTION_H_
