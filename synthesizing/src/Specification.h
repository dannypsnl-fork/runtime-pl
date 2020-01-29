//
// Created by dannypsnl on 2020/1/27.
//

#ifndef SYNTHESIZING_SRC_SPECIFICATION_H_
#define SYNTHESIZING_SRC_SPECIFICATION_H_

#include <cstdint>
#include <vector>
#include "z3.h"

struct Specification {
  virtual unsigned int arity() = 0;

  virtual Z3_bool make_expression(Z3_context context,
                                  std::vector<Z3_ast> inputs, Z3_ast output,
                                  uint32_t bit_width) = 0;

  virtual ~Specification() {}
};

#endif  // SYNTHESIZING_SRC_SPECIFICATION_H_
