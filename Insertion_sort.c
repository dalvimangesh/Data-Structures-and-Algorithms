#include <stdio.h>

//function to swap arr[i] (current element) at its correct position
void swap(long long *arr, int i)
{
    //position for current element and its position
    long long current_element = arr[i];
    int position = i - 1;

    //swaping element to next postion till condition satisfies
    while (position >= 0 && arr[position] > current_element)
    {
        arr[position + 1] = arr[position];
        position--;
    }

    //giving correct position for current element
    arr[position + 1] = current_element;
}

//function to sort
void insertion_sort(long long *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        swap(arr, i);
    }

    //void function
    return;
}

int main()
{
    //reading number of elements in array
    int n;
    scanf("\n %d", &n);

    //reading given array
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("\n %lld", &arr[i]);
    }

    //passing initial address and no of elements as parameter for sorting
    insertion_sort(arr, n);

    //result
    for (int i = 0; i < n; i++)
    {
        printf("%lld\n", arr[i]);
    }

    return 0;
}