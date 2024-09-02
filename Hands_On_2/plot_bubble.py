import matplotlib.pyplot as plt

def plot_graph(x_values, y_values, x_label, y_label, title):
    plt.figure()
    plt.plot(x_values, y_values, marker='o', linestyle='-', color='g')
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.title(title)
    plt.grid(True)
    plt.savefig('plot_bubblesort.png') 
    plt.close()

#insertion sort values 
x = [5, 10, 20, 100, 500, 1000, 5000, 10000]
y = [0.000001, 0.000002, 0.000003, 0.000034, 0.000548, 0.001624, 0.031635, 0.128126]

plot_graph(x, y, 'Input Array Sizes', 'Runtime (secs)', 'Bubble Sort Plot of time vs input size')
