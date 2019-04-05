#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

x = [-7, -5, -1, 0, 2, 5, 6]
y = [15, 12, 5, 2, 0, -5, 9]


slope, intercept, r_value, p_value, std_err = stats.linregress(x, y)
print "Slope: " + str(slope) + "\tIntercept: " + str(intercept)

fit = np.polyfit(x,y,1)
fit_fn = np.poly1d(fit)

plt.plot(x, y, 'yo', label='Original Data')
plt.plot(x, fit_fn(x), 'r', label='Fitted line')
plt.legend()
plt.show()