#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline

T = [5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500, 25000, 27500, 30000]
h = [3.3, 7.5, 41.8, 51.8, 61, 101.1, 132.9, 145.5, 171.4, 225.8, 260.9]

cs = CubicSpline(T, h)
Ts = np.arange(5000, 31000, 500)

print cs(13000)

plt.plot(T, h, 'o', label='Data')
plt.plot(Ts, cs(Ts), label='S')

plt.legend()
plt.show()
