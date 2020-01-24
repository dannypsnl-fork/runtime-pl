//
// Created by dannypsnl on 2020/1/24.
//

#ifndef SYNTHESIZING_SRC_INSTRUCTION_H_
#define SYNTHESIZING_SRC_INSTRUCTION_H_

#include <cstdint>
#include <vector>

typedef uint32_t ID;

enum class OperatorType {
  // comment shows the operands of following operator type
  // 0
  Var,
  Const,
  // 2
  EqualZero,
  Equal,
  NotEqual,
  LessThan,
  LessEqual,
  GreaterThen,
  GreaterEqual,
  Add,
  Sub,
  Mul,
  Div,
  // 3
  Select,
};

class Operand;

class Instruction {
private:
  ID _result;
  OperatorType _op_type;
  std::vector<Operand> _operands;
};

#endif // SYNTHESIZING_SRC_INSTRUCTION_H_
