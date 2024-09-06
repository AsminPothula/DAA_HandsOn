#hands on 3 

#function x = f(n)
#   x = 1;
#   for i = 1:n
#       for j = 1:n
#           x = x + 1;

import time
import matplotlib.pyplot as plt

def f(n): #given function f 
    x = 1
    for i in range(n):  
        for j in range(n):
            x += 1

#time vs n count and plot 
def time_vs_n():
    n_vals = [1, 5, 10, 50, 100, 500, 1000, 2000]  # n values
    times = []  

    for n in n_vals:
        start_time = time.time()
        f(n)  
        elapsed_time = time.time() - start_time
        times.append(elapsed_time) 

    plt.plot(n_vals, times, '-o')
    plt.xlabel('n')
    plt.ylabel('Time (seconds)')
    plt.title('Time vs n')
    plt.savefig('timeplot.png') 
    plt.show()

time_vs_n()
