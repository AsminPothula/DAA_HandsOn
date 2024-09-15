def merge_two_arrays(arr1, arr2):
    merged_array = []
    i, j = 0, 0
    
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            merged_array.append(arr1[i])
            i += 1
        else:
            merged_array.append(arr2[j])
            j += 1
    
    while i < len(arr1):
        merged_array.append(arr1[i])
        i += 1
    
    while j < len(arr2):
        merged_array.append(arr2[j])
        j += 1
    
    return merged_array

def merge_k_arrays(arrays):
    if not arrays:
        return []
    
    merged_result = arrays[0]
    
    for i in range(1, len(arrays)):
        merged_result = merge_two_arrays(merged_result, arrays[i])
    
    return merged_result

if __name__ == "__main__":
    arrayset1 = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]
    arrayset2 = [[1, 3, 7], [2, 4, 8], [9, 10, 11]]
    
    print(merge_k_arrays(arrayset1))
    print(merge_k_arrays(arrayset2))
