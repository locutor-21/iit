#!/usr/bin/python
from math import exp
from scipy.optimize import fsolve

def f(c):
	m = 1
	g = 9.81
	t = 2
	v = -7.2

	return (m*g/c) * (exp(-c*t/m)-1) - v


c_0 = 1
print fsolve(f, c_0)