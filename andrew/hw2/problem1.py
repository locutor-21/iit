#!/usr/bin/python
from math import sin
from scipy.optimize import newton

def f(theta):
	k = 8
	L = 10
	F = 1
	return k*theta-F*L*sin(theta)

theta_0 = 0.9
print newton(f, theta_0, maxiter = 50)