//
// Created by dannypsnl on 2020/1/27.
//

#ifndef SYNTHESIZING_SRC_LIBRARY_H_
#define SYNTHESIZING_SRC_LIBRARY_H_

#include <vector>
#include "Component.h"

class Library {
  std::vector<Component> components;

 public:
  Library() : components{} {}
};

#endif  // SYNTHESIZING_SRC_LIBRARY_H_
