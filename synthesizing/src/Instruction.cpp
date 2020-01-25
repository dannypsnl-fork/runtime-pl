//
// Created by dannypsnl on 2020/1/24.
//

#include "Instruction.h"

Instruction::Instruction(ID id, const Operator &op) : id{id}, op{op} {}

Instruction Instruction::var(ID self_id) { return Instruction(self_id, Var()); }
Instruction Instruction::const_(ID self_id, uint64_t value) {
  return Instruction(self_id, Const(value));
}
Instruction Instruction::equal_zero(ID self_id, ID op1) {
  return Instruction(self_id, EqualZero(op1));
}
Instruction Instruction::equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, Equal(op1, op2));
}
Instruction Instruction::not_equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, NotEqual(op1, op2));
}
Instruction Instruction::less_than(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, LessThan(op1, op2));
}
Instruction Instruction::less_equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, LessEqual(op1, op2));
}
Instruction Instruction::greater_then(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, GreaterThen(op1, op2));
}
Instruction Instruction::greater_equal(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, GreaterEqual(op1, op2));
}
Instruction Instruction::add(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, Add(op1, op2));
}
Instruction Instruction::sub(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, Sub(op1, op2));
}
Instruction Instruction::mul(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, Mul(op1, op2));
}
Instruction Instruction::div(ID self_id, ID op1, ID op2) {
  return Instruction(self_id, Div(op1, op2));
}
Instruction Instruction::select(ID self_id, ID op1, ID op2, ID op3) {
  return Instruction(self_id, Select(op1, op2, op3));
}