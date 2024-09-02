import matplotlib.pyplot as plt

def plot_graph(x_values, y_values, x_label, y_label, title):
    plt.figure()
    plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.title(title)
    plt.grid(True)
    plt.savefig('plot_insertionsort.png') 
    plt.close()

#insertion sort values 
x = [5, 10, 20, 100, 500, 1000, 5000, 10000]
y = [0.000002, 0.000003, 0.000003, 0.000011, 0.000135, 0.000494, 0.014600, 0.045279]

plot_graph(x, y, 'Input Array Sizes', 'Runtime (secs)', 'Insertion Sort Plot of time vs input size')
