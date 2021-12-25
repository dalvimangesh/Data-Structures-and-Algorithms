#include <stdio.h>

/*
if key is present then rescursive function will return
index of that element else it will return -1
*/
int Binary_search(int *a, int low, int high, int key, int *dept)
{
    if (low > high)
        return -1;

    //incrasing dept by 1 (as function call will be increase)
    (*dept)++;

    //mid in floor
    int mid = (low + high) / 2;

    //checking mid value is key or not?
    if (a[mid] == key)
        return mid;

    else if (a[mid] > key) //going for lower half
        return Binary_search(a, low, mid - 1, key, dept);

    else
        return //going for upper half
            Binary_search(a, mid + 1, high, key, dept);
}

int main()
{
    //size of the array
    int n;
    scanf("\n %d", &n);

    //space for array and reading values
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("\n %d", &arr[i]);
    }

    //space for key
    int key;
    scanf("\n %d", &key);

    int dept = 0;

    /* passing starting address lower limit as 0 and 
	higher limit as (n-1) and key and address of dept
    if key is present then res will be equal to index of key 
    if value is not present then it will be -1 */

    int res = Binary_search(arr, 0, n - 1, key, &dept);

    //result
    printf("%d\n", dept);
    printf("%d\n", res);

    return 0;
}