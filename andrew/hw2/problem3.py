#!/usr/bin/python
from math import log10
from math import sqrt
from scipy.optimize import fsolve

def g(f):
	epsilon_D = 0.004
	Re = 200000

	return (1/sqrt(f))+2*log10(epsilon_D/3.7 + 2.51/(Re * sqrt(f)))

f0 = 0.01
print fsolve(g, f0)