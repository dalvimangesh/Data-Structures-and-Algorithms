#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*Function to swap value at two location */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*Function to insert new element in heap at its correct position */
void insert(int *heap, int last, int element)
{
    heap[last] = element; // adding element at last position
    if (last == 0)        // if heap is empty
    {
        return;
    }

    /* by checking parent is small or not then current element if it is 
    then swaping current element with parent then again going for next parent */
    if (heap[(last - 1) / 2] > element)
    {
        swap(&heap[last], &heap[(last - 1) / 2]);
        insert(heap, (last - 1) / 2, element);
    }
}

/* Function to shift_up the given index value at its correct position*/
void shift_up(int *heap, int index)
{
    while (heap[(index - 1) / 2] > heap[index])
    {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

/*Function to minheapfy the given index value at its correct position */
void min_heap_fy(int *heap, int index, int last)
{
    int right = 2 * index + 1;
    int left = 2 * index + 2;
    while (true)
    {
        if (right > last || left > last) //base
            break;

        /*finding min of two child then replacing value in that min*/
        int min = heap[right] > heap[left] ? left : right;
        if (heap[index] > heap[min])
        {
            swap(&heap[min], &heap[index]);

            /*going for min child as parent */
            index = min;
        }
        else
        {
            break;
        }

        right = 2 * index + 1;
        left = 2 * index + 2;
    }
}

/* FUnction to delete value at given index */
void delete (int *heap, int index, int last)
{
    if (index == last) //base
    {
        heap[last] = INT_MIN;
        return;
    }
    swap(&heap[last], &heap[index]);
    heap[last] = INT_MIN;
    last--;

    /* shifting up if possile */
    if (heap[(index - 1) / 2] > heap[index] && index > 0)
    {
        shift_up(heap, index);
    }

    /* else going deep in the heap up to correct place */
    else
    {
        min_heap_fy(heap, index, last);
    }
}

int main()
{
    /* empty heap */
    int heap[200];
    for (int i = 0; i < 200; i++)
    {
        heap[i] = INT_MIN;
    }

    /* space to store the last index of current heap */
    int last = -1;

    /* inserting n element in the heap */
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf(" %d", &element);
        last++;
        insert(heap, last, element);
    }

    /* reading input until end of file */
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1) //insert
        {
            int element;
            scanf(" %d", &element);
            last++;
            insert(heap, last, element);
        }

        if (n == 2) //delete
        {
            int index;
            scanf(" %d", &index);
            if (index > last)
            {
                printf("Operation Fail\n");
                continue;
            }
            delete (heap, index, last);
            last--;
        }

        if (n == 3) //ExtractMin
        /* as this is min heap so min value always at first position */
        {
            printf("%d\n", heap[0]);
            delete (heap, 0, last);
            last--;
        }

        if (n == 4)
        {
            for (int i = 0; i <= last; i++)
            {
                printf("%d\n", heap[i]);
            }
        }

        if (n == 5)
        {
            int index, element;
            scanf(" %d %d", &index, &element);
            if (heap[index] > element && index <= last)
            {
                heap[index] = element;
                shift_up(heap, index);
            }
            else
            {
                printf("Operation Fail\n");
            }
        }

        if (n == 6)
        {
            printf("%d\n", heap[0]);
        }

        if (n == 7)
        {
            break;
        }
    }

    return 0;
}