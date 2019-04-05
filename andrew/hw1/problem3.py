#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

A0 = 0.000125
L0 = 0.0125
F = [24600, 29300, 31500, 33300, 34800, 35700, 36600, 37500, 38800, 39600, 40400]
L = [0.01258, 0.01282, 0.01291, 0.01295, 0.01305, 0.01321, 0.01335, 0.01349, 0.01408, 0.01421, 0.01448]

sigma = []
epsilon = []

for i in range(len(F)):
    sigma.append(F[i] * L[i] / (A0 * L0))
    epsilon.append(np.log(L[i] / L0))


def pow_func(x, a, b):
	ret = []
	for i in x:
	   	ret.append(a * pow(x, b))
	return ret


# sigma = K * (epsilon ** m)
params, params_covariance = curve_fit(pow_func, sigma, epsilon)
print params

plt.scatter(sigma, epsilon, label='Data')
plt.plot(sigma, pow_func(epsilon, params[0], params[1]), 
	label='Fitted function')

plt.legend(loc='best')
plt.show
