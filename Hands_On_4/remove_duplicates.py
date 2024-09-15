def remove_duplicate_elements(arr):
    if len(arr) == 0:
        return arr
    
    index = 0
    for i in range(1, len(arr)):
        if arr[i] != arr[index]:
            index += 1
            arr[index] = arr[i]
    
    return arr[:index + 1]

if __name__ == "__main__":
    array1 = [2, 2, 2, 2, 2]
    print(remove_duplicate_elements(array1))
    
    array2 = [1, 2, 2, 3, 4, 4, 4, 5, 5]
    print(remove_duplicate_elements(array2))
