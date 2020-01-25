//
// Created by dannypsnl on 2020/1/24.
//

#ifndef SYNTHESIZING_SRC_PROGRAM_H_
#define SYNTHESIZING_SRC_PROGRAM_H_

#include <vector>
#include "Instruction.h"

struct Program {
  std::vector<Instruction> instructions;

  explicit Program() : instructions{} {}
};

#endif  // SYNTHESIZING_SRC_PROGRAM_H_
