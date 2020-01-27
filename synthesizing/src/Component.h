//
// Created by dannypsnl on 2020/1/25.
//

#ifndef SYNTHESIZING_SRC_COMPONENT_H_
#define SYNTHESIZING_SRC_COMPONENT_H_

#include <memory>
#include <optional>
#include <vector>
#include "z3.h"

class Operator;
typedef uint32_t ID;

struct Component {
  /// How many operands does this component take?
  virtual unsigned int operand_arity() = 0;
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
  virtual std::shared_ptr<Operator> make_operator(
      std::vector<uint64_t> immediates, std::vector<ID> operands) = 0;
};

#endif  // SYNTHESIZING_SRC_COMPONENT_H_
