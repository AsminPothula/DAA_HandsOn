#calculate the bounds by slightly increasing and decreasing the polynomial coefficients
#plot the original data, polynomial fir, upper bound, lower bound 

import time
import matplotlib.pyplot as plt
import numpy as np

def f(n):
    x = 1
    for i in range(n):  
        for j in range(n):
            x += 1

def time_f_vs_n():
    n_vals = [1, 5, 10, 50, 100, 500, 1000, 2000] 
    times = []

    for n in n_vals:
        start_time = time.time()
        f(n)
        elapsed_time = time.time() - start_time
        times.append(elapsed_time)

    p = np.polyfit(n_vals, times, 2) 
    print("Polynomial coefficients (degree 2):", p)

    poly_func = np.poly1d(p) 

    n_smooth = np.linspace(min(n_vals), max(n_vals), 100)
    time_fit = poly_func(n_smooth) 

    upper_bound = np.poly1d(p * 1.1)  #increase coefficients 
    lower_bound = np.poly1d(p * 0.9)  #decrease coefficients

    time_upper = upper_bound(n_smooth)
    time_lower = lower_bound(n_smooth)  

    plt.plot(n_vals, times, '-o', label='Original Data')
    plt.plot(n_smooth, time_fit, '-', label='Polynomial Fit (degree 2)')
    plt.plot(n_smooth, time_upper, '--', label='Upper Bound') 
    plt.plot(n_smooth, time_lower, '--', label='Lower Bound')

    plt.xlabel('n')
    plt.ylabel('Time (seconds)')
    plt.title('Time vs n with Polynomial Fit and Bounds')
    plt.legend()
    plt.savefig('timeplot_fit_bounds.png')
    plt.show()

    return n_vals, times, poly_func

n_vals, times, poly_func = time_f_vs_n()
