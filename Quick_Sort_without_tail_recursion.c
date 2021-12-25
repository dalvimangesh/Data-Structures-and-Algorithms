#include <stdio.h>

//function to swap the the value of two locations
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//function to pivot along last element(right) of input array
int pivot_along(int *arr, int left, int right)
{
    //pivot element
    int pivot = arr[right];

    //smaller index
    int num = left - 1;

    //doing partitions
    for (int i = left; i <= right - 1; i++)
    {
        //pivoting along pivot element
        if (arr[i] < pivot)
        {
            //increasing smaller value as we are swaping
            num++;
            swap(&arr[i], &arr[num]);
        }
    }

    swap(&arr[num + 1], &arr[right]);

    //returning rank
    return num + 1;
}

//function to sort the array using partitions
void quick_sort(int *arr, int left, int right)
{
    //base condition
    while (left < right)
    {
        //rank
        int p_index = pivot_along(arr, left, right);

        //recursivaly sorting

        //going for left part of pivot index
        quick_sort(arr, left, p_index - 1);

        //going for right part of pivot index
        left = p_index + 1;
    }
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

    quick_sort(arr, 0, n - 1);

    //result
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}