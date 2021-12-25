#include <stdio.h>

//function to swap values at two locations
void swap(long long *a, long long *b)
{
    long long temp = *a;
    *a = *b;
    *b = temp;
}

/*function to find max element of smaller 
array and giving it last position of smaller array*/
void max_index_exchange(long long *a, int n, int i)
{
    //space to store current max element and its index
    long long max_element, max_element_index;

    //assuming the first element is max element
    max_element = a[0];
    max_element_index = 0;

    //loop to calculate max element in first (n-i) elements of array
    for (int j = 0; j < n - i; j++)
    {
        if (a[j] > max_element)
        {
            //changing max element and its index
            max_element_index = j;
            max_element = a[j];
        }
    }

    //swaping (ith) max element at (n-i)th position
    swap(&a[max_element_index], &a[n - i - 1]);
}

//function to sort array in increasing order
void selection_sort(long long *a, int n)
{
    //iterating for each n-1 max elements
    for (int i = 0; i < n - 1; i++)
    {
        max_index_exchange(a, n, i);
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
    selection_sort(arr, n);

    //result
    for (int i = 0; i < n; i++)
    {
        printf("%lld\n", arr[i]);
    }

    return 0;
}