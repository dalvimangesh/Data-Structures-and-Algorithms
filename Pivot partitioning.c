#include <stdio.h>

//function to swap the the value of two locations
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
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

    //space for pivot index
    int k;
    scanf("\n %d", &k);

    int pivot = arr[k];

    int rank = 0;

    //counting no of elements less than pivot
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[k])
            rank++;
    }

    //exchanging value
    swap(&arr[k], &arr[rank]);

    //creating and initilising two varibales for iteration
    int i = 0, j = rank + 1;

    while (i < rank && j < n)
    {
        //going for rightmost value on the left side of pivot place
        while (i < rank && arr[i] < arr[rank])
        {
            i++;
        }

        //going for rightmost value on the right side of pivot place
        while (j < n && arr[j] >= arr[rank])
        {
            j++;
        }

        //swaping the values if possible
        if (i < rank && j < n)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j++;
        }
    }

    //result
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}