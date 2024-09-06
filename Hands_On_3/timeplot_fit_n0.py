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

    plt.plot(n_vals, times, '-o', label='Original Data')  
    plt.plot(n_smooth, time_fit, '-', label='Polynomial Fit (degree 2)') 

    #according to my observation of the plot, it looks the data points startdeviating from the polynomial fit from n=1000
    #so n0 = 1000
    n_0 = 1000
    plt.axvline(x=n_0, color='red', linestyle='--', label=f'n₀ ≈ {n_0}')
    plt.text(n_0, np.max(times), f'n₀ ≈ {n_0}', color='red', verticalalignment='top')
    plt.xlabel('n')
    plt.ylabel('Time (seconds)')
    plt.title('Time vs n with Polynomial Fit and n₀')
    plt.legend()
    plt.xlim(0, max(n_vals) // 1.55)  #zoom 
    plt.savefig('timeplot_fit_n0.png')
    plt.show()

    return n_vals, times, poly_func, n_0

n_vals, times, poly_func, n_0 = time_f_vs_n()
