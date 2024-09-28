import random

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr, low, high):
    random_index = random.randint(low, high)  
    swap(arr, random_index, high)
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)

    swap(arr, i + 1, high)
    return i + 1

def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quicksort(arr, low, pi - 1)
        quicksort(arr, pi + 1, high)

def main():
    n = int(input("Enter the number of elements: "))
    arr = list(map(int, input(f"Enter {n} elements: ").split()))
    if len(arr) != n:
        print(f"Error: Expected {n} elements but got {len(arr)} elements.")
        return

    print("Original array:", arr)
    quicksort(arr, 0, n - 1)
    print("Sorted array:", arr)

if __name__ == "__main__":
    main()
