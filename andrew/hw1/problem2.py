#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import linregress
from scipy.optimize import curve_fit

x = [1850, 1900, 1950, 1980, 2000]
y = [1.3, 1.6, 3.0, 4.4, 6.0]

plt.plot(x, y, 'o', label='Data')
plt.show()
###
def linear_regression(x, y):
    slope, intercept, r_value, p_value, std_err = linregress(x, y)
    return slope, intercept


def func_exp(x, a0, a1):
    ret = []
    for i in x:
    	ret.append(a0 * np.exp(a1 * i))
    return ret


a0, a1 = andrewSucks(x, y)
print str(a0) + " " + str(a1)

popt, pcov = curve_fit(func_exp, x, y)
print popt

plt.plot(x, y, 'o', label='Data')
plt.plot(x, func_exp(x, *popt), 'r-', label='fit')
plt.show()
###