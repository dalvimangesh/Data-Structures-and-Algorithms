#include <stdio.h>

//function to merge two sorted parts of in sorting order
void merge(int *a, int *result, int low, int mid, int high)
{
    //space for iterating over left part of mid
    int i = low;

    //space for iterationg over right part of mid
    int j = mid + 1;

    //space to iterating from low to high
    int index = low;

    //merging two parts in sorted order
    while (i <= mid && j <= high)
    {
        //checking current left array element and curent right array elementis small or not?

        if (a[i] < a[j])
        {
            result[index] = a[i];
            i++;
        }
        else
        {
            result[index] = a[j];
            j++;
        }

        index++;
    }

    //if j is at high then some iterations of i might be left
    while (i <= mid)
    {
        result[index] = a[i];
        i++;
        index++;
    }

    //if i is at low then some iterations of j might be left
    while (j <= high)
    {
        result[index] = a[j];
        j++;
        index++;
    }

    //replacing given sorted part in original array
    for (int i = low; i <= high; i++)
    {
        a[i] = result[i];
    }
}

//function to sort the array using dividing then joining methode
void merge_sort(int *a, int *result, int low, int high)
{
    //base condition
    if (low >= high)
        return;

    //mid index
    int mid = (high + low) / 2;

    //recursive call to sort current left part
    merge_sort(a, result, low, mid);

    //recursive call to sort current right part
    merge_sort(a, result, mid + 1, high);

    //merging the current left and right part
    merge(a, result, low, mid, high);
}

int main()
{
    //space for number of elements in array
    int n;
    scanf("\n %d", &n);

    //reading user array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("\n %d", &arr[i]);
    }

    //array to store the sorting result
    int result[n];

    //sorting array using merge sort
    merge_sort(arr, result, 0, n - 1);

    //result
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}