from z3 import *

x = BitVec("x", 8)
y = BitVec("y", 8)
n = BitVec("n", 8)

phi_in = y == x * 2
phi_synthe = y == x << n

encoding = ForAll([x, y], phi_in == phi_synthe)

s = Solver()
s.add(encoding)

s.check()

print(s.model())
