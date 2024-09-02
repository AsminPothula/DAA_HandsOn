#Selection Sort is correct because it continually chooses the smallest unsorted element and moves it to the appropriate location in the sorted section of the array. 
#The algorithm sorts the left half of the array after each iteration, and it keeps going until the entire array is sorted.

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def is_sorted(arr):
    return all(arr[i] <= arr[i+1] for i in range(len(arr) - 1))

#array input size = 25
array = [64, 25, 12, 22, 11, 90, 88, 57, 77, 23, 9, 21, 65, 13, 40, 36, 47, 84, 50, 29, 73, 51, 8, 96, 39]
selection_sort(array)

#check if the array is sorted
if is_sorted(array):
    print("The array is sorted correctly:", array)
else:
    print("The array is not sorted correctly:", array)
