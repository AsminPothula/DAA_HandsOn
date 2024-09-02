import matplotlib.pyplot as plt

# Data for Selection Sort
x_sel = [5, 10, 20, 100, 500, 1000, 5000, 10000]
y_sel = [0.000001, 0.000002, 0.000003, 0.000017, 0.000369, 0.000863, 0.018788, 0.071616]

# Data for Insertion Sort
x_ins = [5, 10, 20, 100, 500, 1000, 5000, 10000]
y_ins = [0.000002, 0.000003, 0.000003, 0.000011, 0.000135, 0.000494, 0.014600, 0.045279]

# Data for Bubble Sort
x_bub = [5, 10, 20, 100, 500, 1000, 5000, 10000]
y_bub = [0.000001, 0.000002, 0.000003, 0.000034, 0.000548, 0.001624, 0.031635, 0.128126]

# Plotting
plt.figure()
plt.plot(x_sel, y_sel, marker='o', linestyle='-', color='r', label='Selection Sort')
plt.plot(x_ins, y_ins, marker='o', linestyle='-', color='b', label='Insertion Sort')
plt.plot(x_bub, y_bub, marker='o', linestyle='-', color='g', label='Bubble Sort')

plt.xlabel('Input Array Sizes')
plt.ylabel('Runtime (secs)')
plt.title('Benchmark - Insertion, Selection, and Bubble Sorts')
plt.grid(True)
plt.legend()
plt.savefig('benchmark_sorting_algorithms.png')
plt.show()
