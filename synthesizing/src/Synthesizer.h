//
// Created by dannypsnl on 2020/1/29.
//

#ifndef SYNTHESIZING_SRC_SYNTHESIZER_H_
#define SYNTHESIZING_SRC_SYNTHESIZER_H_

#include <memory>
#include "Library.h"
#include "Specification.h"
#include "z3.h"

class Synthesizer {
  Z3_context _ctx;
  const Library &_library;
  std::unique_ptr<Specification> _specification;

 public:
  Synthesizer(Z3_context ctx, const Library &library,
              std::unique_ptr<Specification> specification)
      : _ctx{ctx},
        _library{library},
        _specification{std::move(specification)} {}
  ~Synthesizer() { Z3_del_context(_ctx); }
};

#endif  // SYNTHESIZING_SRC_SYNTHESIZER_H_
