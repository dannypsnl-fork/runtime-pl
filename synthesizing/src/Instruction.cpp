//
// Created by dannypsnl on 2020/1/24.
//

#include "Instruction.h"

Instruction Instruction::var(ID self_id) {
  Var inst;
  inst.id = self_id;
  return inst;
}
Instruction Instruction::const_(ID self_id, uint64_t value) {
  Const inst;
  inst.id = self_id;
  inst.value = value;
  return inst;
}
Instruction Instruction::equal_zero(ID self_id, ID op1) {
  EqualZero inst;
  inst.id = self_id;
  inst.operand = op1;
  return inst;
}
Instruction Instruction::equal(ID self_id, ID op1, ID op2) {
  Equal inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::not_equal(ID self_id, ID op1, ID op2) {
  NotEqual inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::less_than(ID self_id, ID op1, ID op2) {
  LessThan inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::less_equal(ID self_id, ID op1, ID op2) {
  LessEqual inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::greater_then(ID self_id, ID op1, ID op2) {
  GreaterThen inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::greater_equal(ID self_id, ID op1, ID op2) {
  GreaterEqual inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::add(ID self_id, ID op1, ID op2) {
  Add inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::sub(ID self_id, ID op1, ID op2) {
  Sub inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::mul(ID self_id, ID op1, ID op2) {
  Mul inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::div(ID self_id, ID op1, ID op2) {
  Div inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  return inst;
}
Instruction Instruction::select(ID self_id, ID op1, ID op2, ID op3) {
  Select inst;
  inst.id = self_id;
  inst.operand1 = op1;
  inst.operand2 = op2;
  inst.operand3 = op3;
  return inst;
}
