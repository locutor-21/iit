#!/usr/bin/python
from math import sin, exp

def f(theta):
	k = 8
	L = 10
	F = 1
	return k*theta-F*L*sin(theta)

def g(c):
	m = 1
	g = 9.81
	t = 2
	v = -7.2
	return (m*g/c) * (exp(-c*t/m)-1) - v

def bisection(f, a, b, tol=1.48e-08):
	c = (a+b)/2.0
	while (b-a)/2.0 > tol:
		if f(c) == 0:
			return c
		elif f(a)*f(c) < 0:
			b = c
		else:
			a = c
		c = (a+b)/2.0
	return c

print "#1: " + str(bisection(f, 0.5, 2))
print "#2: " + str(bisection(g, 0.5, 2))
