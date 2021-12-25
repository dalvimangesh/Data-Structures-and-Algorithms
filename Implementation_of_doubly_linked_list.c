#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//double linked list
struct node
{
    int item;
    struct node *next;
    struct node *previous;
};

typedef struct node list;

/* Funtion to check wheather main stack 
is full or not by creating new space*/
bool is_possible()
{
    list *element = (list *)malloc(sizeof(list));
    if (element == NULL)
    {
        return false;
    }
    return true;
}

/* function to add new node in current double
linked list by creating new space for new element*/
list *add(list *ptr, int number)
{
    if (!is_possible())
    {
        return ptr;
    }

    list *element = (list *)malloc(sizeof(list));
    element->item = number;
    element->next = NULL;
    element->previous = NULL;

    /* means current linked list is emptyso element
    to add will be front and end of double linked list*/
    if (ptr == NULL)
    {
        return element;
    }

    /*add new node at the end of double linked list */
    ptr->next = element;
    element->previous = ptr;
    return element;
}

/* function to print all the element of current
double linked list from front to end */
void Display_from_front(list *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->item);
        ptr = ptr->next;
    }
}

/* function to print all the element of current
double linked list from end to front */
void Display_from_end(list *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->item);
        ptr = ptr->previous;
    }
}

int main()
{
    //creating empty double linked list
    list *front = NULL;
    list *end = NULL;

    //space to store number of element
    int n = 0;
    scanf("\n%d", &n);

    //for input
    for (int i = 0; i < n; i++)
    {
        //space for current element item
        int number = 0;
        scanf("\n%d", &number);

        //means current double linked list is empty
        if (front == NULL)
        {
            front = add(front, number);
            end = front;
        }
        else
        {
            end = add(end, number);
        }
    }

    Display_from_front(front); //printing from front to end
    Display_from_end(end);     //printing from end to front

    //deleting front element if present
    if (front != NULL)
    {
        list *temp = front;
        front = front->next;
        front->previous = NULL;
        free(temp); //free space of front element
    }

    //deleting end element if present
    if (end != NULL)
    {
        list *temp = end;
        end = end->previous;
        end->next = NULL;
        free(temp); //free space of end element
    }

    Display_from_front(front); //printing from front to end
    Display_from_end(end);     //printing from end to front

    return 0;
}