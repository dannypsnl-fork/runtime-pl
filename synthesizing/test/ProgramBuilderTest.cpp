//
// Created by dannypsnl on 2020/1/25.
//

#include "ProgramBuilder.h"
#include "gtest/gtest.h"

TEST(ProgramBuilder, ID_increasing) {
  ProgramBuilder builder{};
  auto c1 = builder.const_(1);
  auto c2 = builder.const_(2);
  auto add_id = builder.add(c1, c2);
  ASSERT_EQ(add_id, 2);
}
