//-----------------------------------------------------------------------------
//---------------------------Searching Algorithm-------------------------------
//-----------------------------------------------------------------------------

//===================Linear Search=========================

#include <stdio.h>

int linear_search(int arr[], int size, int element) // ---> O(n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

//===================Self made array===================

    int size, element;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &element);
    int search = linear_search(arr, size, element);
    printf("%d is found at index %d", element, search);

//==================Pre defined array====================

    int arr[] = {3, 5, 6, 10, 13, 55, 66, 77, 99, 33, 35, 11, 16, 100, 300};
    int element;
    int size = sizeof(arr) / sizeof(int);
    printf("Enter the element to search: ");
    scanf("%d", &element);
    int search = linear_search(arr, size, element);
    printf("%d is found at index %d", element, search);

    return 0;
}

//===================Binary Search======================

int binary_search(int arr[], int size, int element) // ---> O(logn)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    //=========Pre defined sorted array in ascending order=========

    int arr[] = {3, 5, 6, 10, 11, 13, 16, 33, 35, 55, 66, 77, 99, 100, 300};
    int element;
    int size = sizeof(arr) / sizeof(int);
    printf("Enter the element to search: ");
    scanf("%d", &element);
    int search = binary_search(arr, size, element);
    printf("%d is found at index %d", element, search);

    return 0;
}


//------------------------------------------------------------------------------------------------------
//--------------------------------------------- Sorting Algorithm --------------------------------------
//------------------------------------------------------------------------------------------------------


//=============Bubble short================

#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of pass
    {
        for (int j = 0; j < n - 1 - i; j++) // for comparision in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
// Your code starts here
int arr[] = {12, 54, 65, 7, 23, 9};
int n = 6;
printf("Before: ");
printArray(arr, n);
bubble_sort(arr, n);
printf("After: ");
printArray(arr, n);

    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, size);
    printArray(arr, size);

    return 0;
}

//=============Insertion Sort=====================

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++) // for  passes
    {
        key = arr[i];
        j = i - 1;
        // for comparison and shifting
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // inserting key at its correct position in sorted array
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Your code starts here
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printf("Before: ");
    printArray(arr, n);
    insertion_sort(arr, n);
    printf("After: ");
    printArray(arr, n);
    return 0;
}

//=============Selection Sort=====================

#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int n)
{
    int min_index, temp;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Your code starts here
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printf("Before: ");
    printArray(arr, n);
    selection_sort(arr, n);
    printf("After: ");
    printArray(arr, n);

int size;
printf("Enter array size: ");
scanf("%d", &size);
int arr[size];
for (int i = 0; i < size; i++)
{
    scanf("%d", &arr[i]);
}
selection_sort(arr, size);
printArray(arr, size);

return 0;
}

//====================Merge Sort====================

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)

{
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    for (int p = 0; p < k; p++)
    {
        arr[low + p] = temp[p];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

//====================Quick Sort====================

#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    // Swap arr[low] and arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int arr[], int low, int high)
{
    int partition_index;

    if (low < high)
    {
        partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);  // sort left sub array
        quick_sort(arr, partition_index + 1, high); // sort right sub array
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Your code starts here

    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printf("Before: ");
    printArray(arr, n);
    quick_sort(arr, 0, n - 1);
    printf("After: ");
    printArray(arr, n);

    return 0;
}
