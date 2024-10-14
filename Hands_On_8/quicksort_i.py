def swap(a, b):
    return b, a

def partition(arr, low, high):
    pivot = arr[high] 
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = swap(arr[i], arr[j])
    arr[i + 1], arr[high] = swap(arr[i + 1], arr[high])
    return i + 1

def quicksort_i(arr, low, high, k):
    if low <= high:
        pi = partition(arr, low, high)
        
        #if the pivot = k-th smallest element
        if pi == k:
            return arr[pi]
        #if the k-th smallest is on the left side of the pivot
        elif pi > k:
            return quicksort_i(arr, low, pi - 1, k)
        #if the k-th smallest is on the right side of the pivot
        else:
            return quicksort_i(arr, pi + 1, high, k)
    
    return None 

def main():
    n = int(input("Enter the number of elements: "))
    arr = []
    print(f"Enter {n} elements: ", end="")
    arr = list(map(int, input().split()))

    k = int(input("Enter the order statistic to find (smallest index is 0th): "))

    if k < 0 or k >= n:
        print("Index out of bounds.")
        return

    print("Original array:", ' '.join(map(str, arr)))
    result = quicksort_i(arr, 0, n - 1, k)
    print(f"The {k}-th order statistic is: {result}")

if __name__ == "__main__":
    main()
