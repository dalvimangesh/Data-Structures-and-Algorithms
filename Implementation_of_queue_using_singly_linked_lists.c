#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* linked list */
struct node
{
    int item;
    struct node *next;
};
typedef struct node queue;

/* Funtion to check wheather main stack 
is full or not by creating new space*/
bool is_possible()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {
        return false;
    }
    return true;
}

/* Function to check queue is empty or not */
bool IsEmpty(queue *q)
{
    if (q == NULL)
    {
        return true;
    }
    return false;
}

/* if possible, Adding element to the tail of 
the queue by creating space for element and 
then making it as the tail of the queue */
queue *Enqueue(queue *q, int value)
{
    if (!is_possible())
    {
        printf("Enqueue Failure\n");
        return q;
    }

    queue *element = (queue *)malloc(sizeof(queue));

    element->item = value;
    element->next = NULL;

    if (q == NULL) //Means Current queue is NULL
    {
        return element;
    }

    q->next = element;
    return element;
}

/* if possible deleting front element of 
the queue and the making next element
as the head of the queue */
queue *Dequeue(queue *q)
{
    if (IsEmpty(q))
    {
        printf("Dequeue Failure\n");
        return q;
    }

    printf("%d\n", q->item);
    queue *temp = (queue *)malloc(sizeof(queue));
    temp = q;
    q = q->next;
    free(temp);
    return q;
}

/* if possible , printing front element of the queue */
void Peek(queue *q)
{
    if (IsEmpty(q))
    {
        printf("Error\n");
    }
    printf("%d\n", q->item);
    return;
}

/* if possible , Displaying all element 
from the front to back */
void Display(queue *q)
{
    if (IsEmpty(q))
    {
        printf("Empty List\n");
        return;
    }
    queue *traverse = q;
    while (traverse != NULL)
    {
        printf("%d\n", traverse->item);
        traverse = traverse->next;
    }
    return;
}

int main()
{
    //creating NULL queue
    queue *q = NULL;
    queue *tail = NULL;

    //to store function call from user
    int x = 0;

    //base condition
    while (x != 5)
    {
        //input for function call
        scanf("\n%d", &x);

        if (x == 0) // IsEmpty
        {
            if (IsEmpty(q))
            {
                printf("Empty\n");
            }
            else
            {
                printf("Non Empty\n");
            }
        }

        if (x == 1) //Enqueue
        {
            int element = 0;
            scanf("\n%d", &element);

            if (q == NULL) //Means Current queue is NULL
            {
                q = Enqueue(q, element);
                tail = q;
            }
            else
            {
                tail = Enqueue(tail, element);
            }
        }

        if (x == 2) //Dequeue
        {
            q = Dequeue(q);
        }

        if (x == 3) //Peek
        {
            Peek(q);
        }

        if (x == 4) //Display
        {
            Display(q);
        }
    }

    return 0;
}