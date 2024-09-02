#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

#ifdef PRINTARRAY
#include <stdio.h>
#endif

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void PrintArray(int ArrayToPrint[], int SizeAP)
{
    int i;
    for (i = 0; i < SizeAP; i++)
    {
        printf("%d\n", ArrayToPrint[i]);
    }
}

int* GenerateRandomArray(int size)
{
    srand(time(NULL));  // Seed the random number generator
    int *arr = (int *)malloc(size * sizeof(int));
    
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;  // Generate a random number between 0 and 999
    }

    return arr;
}

int main()
{
    clock_t start, end;

    int size;
    printf("Enter the input array size: ");
    scanf("%d", &size);

    int *arr = GenerateRandomArray(size);

    #ifdef PRINTARRAY
    printf("Array before sorting:\n");
    PrintArray(arr, size);
    printf("\n");
    #endif

    start = clock();
    selectionSort(arr, size);
    end = clock();

    #ifdef PRINTARRAY
    printf("Array after sorting:\n");
    PrintArray(arr, size);
    printf("\nProcessed %d records\n", size);
    #endif

    double runtime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSelection Sort = %ld Tics\n\n", (end - start));
    printf("Runtime = %f seconds\n\n", runtime);
    
    free(arr);  

    return 0;
}
