//
// Created by dannypsnl on 2020/1/24.
//

#include <memory>
#include "ProgramBuilder.h"
#include "Synthesizer.h"
#include "z3.h"

int main() {
  Z3_config cfg = Z3_mk_config();
  Z3_context ctx = Z3_mk_context(cfg);
  Library lib{};
  ProgramBuilder builder{};
  builder.mul(builder.var(), builder.var());
  std::unique_ptr<Specification> spec = builder.build();  // Program
  Synthesizer synthesizer{ctx, lib, std::move(spec)};
  Z3_del_config(cfg);
  return 0;
}
