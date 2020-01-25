//
// Created by dannypsnl on 2020/1/24.
//

#include "ProgramBuilder.h"

std::unique_ptr<Program> ProgramBuilder::build() { return std::move(_program); }
ID ProgramBuilder::_next_id() { return ID(_program->instructions.size()); }
ID ProgramBuilder::var() {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::var(id));
  return id;
}
ID ProgramBuilder::const_(uint64_t value) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::const_(id, value));
  return id;
}
ID ProgramBuilder::equal_zero(ID op1) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::equal_zero(id, op1));
  return id;
}
ID ProgramBuilder::equal(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::equal(id, op1, op2));
  return id;
}
ID ProgramBuilder::not_equal(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::not_equal(id, op1, op2));
  return id;
}
ID ProgramBuilder::less_than(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::less_than(id, op1, op2));
  return id;
}
ID ProgramBuilder::less_equal(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::less_equal(id, op1, op2));
  return id;
}
ID ProgramBuilder::greater_then(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::greater_then(id, op1, op2));
  return id;
}
ID ProgramBuilder::greater_equal(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::greater_equal(id, op1, op2));
  return id;
}
ID ProgramBuilder::add(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::add(id, op1, op2));
  return id;
}
ID ProgramBuilder::sub(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::sub(id, op1, op2));
  return id;
}
ID ProgramBuilder::mul(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::mul(id, op1, op2));
  return id;
}
ID ProgramBuilder::div(ID op1, ID op2) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::div(id, op1, op2));
  return id;
}
ID ProgramBuilder::select(ID op1, ID op2, ID op3) {
  auto id = _next_id();
  _program->instructions.push_back(Instruction::select(id, op1, op2, op3));
  return id;
}