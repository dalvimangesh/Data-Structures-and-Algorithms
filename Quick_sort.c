#include <stdio.h>

//function to swap the the value of two locations
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//function to pivot along given element
void pivot_along(int *arr, int left, int right, int pivot_index, int n)
{
    while (left < pivot_index && right < n)
    {
        //going for rightmost value on the left side of pivot place
        while (left < pivot_index && arr[left] < arr[pivot_index])
        {
            left++;
        }

        //going for rightmost value on the right side of pivot place
        while (right < n && arr[right] >= arr[pivot_index])
        {
            right++;
        }

        //swaping the values if possible
        if (left < pivot_index && right < n)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right++;
        }
    }
}

//function to sort the array using partitions
void quick_sort(int *arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    int pivot = arr[0];

    int rank = 0;

    //counting no of elements less than pivot
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[0])
            rank++;
    }

    //exchanging value
    swap(&arr[0], &arr[rank]);

    //creating and initilising two varibales for iteration
    int i = 0, j = rank + 1;

    //using function to pivot
    pivot_along(arr, i, j, rank, n);

    //now sorting left part of the pivot
    quick_sort(arr, rank);

    //now sorting right part of the pivot
    quick_sort(arr + rank + 1, n - rank - 1);
}

int main()
{
    //space for number of elements in array
    int n;
    scanf("\n %d", &n);

    //rading user array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("\n %d", &arr[i]);
    }

    quick_sort(arr, n);

    //result
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}