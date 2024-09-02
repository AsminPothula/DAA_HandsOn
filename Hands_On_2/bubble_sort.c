#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

#ifdef PRINTARRAY
#include <stdio.h>
#endif

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSort(arr, size);
    end = clock();

    #ifdef PRINTARRAY
    printf("Array after sorting:\n");
    PrintArray(arr, size);
    printf("\nProcessed %d records\n", size);
    #endif

    double runtime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nBubble Sort = %ld Tics\n\n", (end - start));
    printf("Runtime = %f seconds\n\n", runtime);
    
    free(arr);  

    return 0;
}
