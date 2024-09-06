#outputs fitted curve along with original data points 
import time
import matplotlib.pyplot as plt
import numpy as np

def f(n):
    x = 1
    for i in range(n):  
        for j in range(n):
            x += 1

def time_f_vs_n():
    n_vals = [1, 5, 10, 50, 100, 500, 1000, 2000] #n values
    times = [] 

    for n in n_vals:
        start_time = time.time()
        f(n)
        elapsed_time = time.time() - start_time
        times.append(elapsed_time)
    
    #this calculated the coefficients of the polynomial considered (quad) base don the n values and corresponding times 
    p = np.polyfit(n_vals, times, 2)  #considering the degree as 2 (quadratic)
    print("Polynomial coefficients (degree 2):", p) #polyfit function outputs the values of the coefficients 

    #this creates the actualy polynomial fucntion (equation) based on the coefficients calculated
    # like ax^2 + bx + c = 0
    poly_func = np.poly1d(p)

    #since we have n values like(1, 5, 10, 100,...) it is discrete values. 
    #but to get a smoother/continuous curve, we smooth the n values (i.e., get consider continoous values for n)
    n_smooth = np.linspace(min(n_vals), max(n_vals), 100)
    time_fit = poly_func(n_smooth) #calculate corresponding times for all the smoothened n values 

    #plotting
    plt.plot(n_vals, times, 'o', label='Original Data')  # only show original data points
    plt.plot(n_smooth, time_fit, '-', label='Polynomial Fit (degree 2)')  # polynomial fitted curve
    plt.xlabel('n')
    plt.ylabel('Time (seconds)')
    plt.title('Time vs n with Polynomial Fit')
    plt.legend()

    plt.savefig('timeplot_fit.png')
    plt.show()

    return n_vals, times, poly_func

n_vals, times, poly_func = time_f_vs_n()