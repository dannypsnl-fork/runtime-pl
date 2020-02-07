#include "z3++.h"
#include <iostream>

using z3::expr;

void demorgan();

int main() { demorgan(); }

void demorgan() {
  z3::config cfg{};
  z3::context c{cfg};
  expr x = c.bool_const("x");
  expr y = c.bool_const("y");
  expr we_believe = (!(x && y)) == (!x || !y);
  z3::solver solver{c};
  solver.add(!we_believe);
  std::cout << solver.to_smt2() << std::endl;
  switch (solver.check()) {
  case z3::unsat:
    std::cout << "demorgan is valid" << std::endl;
    break;
  case z3::sat:
    std::cout << "demorgan is invalid" << std::endl;
    break;
  case z3::unknown:
    std::cout << "unknown error" << std::endl;
    break;
  }
}
