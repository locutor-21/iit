#!/usr/bin/python
from scipy.optimize import fsolve

def equations(p):
	x1, x2 = p
	return (4*x1**2 - x2**3 + 28, 3*x1**3 + 4*x2**2 - 145)

x1_0 = 1
x2_0 = 1
solve = fsolve(equations, (x1_0,x2_0))
print "x1: " + str(solve[0]) + "\nx2: " + str(solve[1])