//
// Created by dannypsnl on 2020/1/24.
//

#ifndef SYNTHESIZING_SRC_PROGRAMBUILDER_H_
#define SYNTHESIZING_SRC_PROGRAMBUILDER_H_

#include <memory>

#include "Program.h"

class ProgramBuilder {
private:
  std::unique_ptr<Program> _program;

public:
  explicit ProgramBuilder() { _program = std::make_unique<Program>(Program()); }
  std::unique_ptr<Program> build();
  ID var();
  ID const_(uint64_t value);
  ID equal_zero(ID op1);
  ID equal(ID op1, ID op2);
  ID not_equal(ID op1, ID op2);
  ID less_than(ID op1, ID op2);
  ID less_equal(ID op1, ID op2);
  ID greater_then(ID op1, ID op2);
  ID greater_equal(ID op1, ID op2);
  ID add(ID op1, ID op2);
  ID sub(ID op1, ID op2);
  ID mul(ID op1, ID op2);
  ID div(ID op1, ID op2);
  ID select(ID op1, ID op2, ID op3);

private:
  ID _next_id();
};

#endif // SYNTHESIZING_SRC_PROGRAMBUILDER_H_
