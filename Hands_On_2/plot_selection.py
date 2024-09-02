import matplotlib.pyplot as plt

def plot_graph(x_values, y_values, x_label, y_label, title):
    plt.figure()
    plt.plot(x_values, y_values, marker='o', linestyle='-', color='r')
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.title(title)
    plt.grid(True)
    plt.savefig('plot_selectionsort.png') 
    plt.close()

#insertion sort values 
x = [5, 10, 20, 100, 500, 1000, 5000, 10000]
y = [0.000001, 0.000002, 0.000003, 0.000017, 0.000369, 0.000863, 0.018788, 0.071616]

plot_graph(x, y, 'Input Array Sizes', 'Runtime (secs)', 'Selection Sort Plot of time vs input size')
