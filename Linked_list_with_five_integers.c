#include <stdio.h>

//creating node
struct node
{
    int num;

    //for storing address of next node
    struct node *next_node;
};

int main()
{
    //space for five node's and reading there values
    struct node node1, node2, node3, node4, node5;

    scanf(" %d", &node1.num);
    node1.next_node = &node2;

    scanf(" %d", &node2.num);
    node2.next_node = &node3;

    scanf(" %d", &node3.num);
    node3.next_node = &node4;

    scanf(" %d", &node4.num);
    node4.next_node = &node5;

    scanf(" %d", &node5.num);

    // terminating list
    node5.next_node = NULL;

    //creating node pointer for the head of the linked list
    struct node *head = &node1;

    //node pointer for the iteration
    struct node *next = NULL;
    next = head;

    //printing all the elements of the list
    while (next != NULL)
    {
        printf("%d\n", next->num);
        next = next->next_node;
    }

    //input for x
    struct node x;
    scanf(" %d", &x.num);

    //node pointer for storing last node address
    struct node *previous = NULL;

    //for iteration from start of list
    next = head;

    //space to store count
    int cnt = 0;

    while (next != NULL)
    {
        //given condition
        if ((next->num) > (x.num))
        {
            //count=0 means we have to insert element at start
            if (cnt == 0)
            {
                //giving value of the next node
                x.next_node = next;
                break;
            }

            //giving value of the next node
            x.next_node = next;

            //giving value of x to the previous node
            previous->next_node = &x;
            break;
        }

        //going for next value's
        cnt++;
        previous = next;
        next = next->next_node;
    }

    //inserting element at last
    if (cnt == 5)
    {
        previous->next_node = &x;
        x.next_node = NULL;
    }

    //count=0 means we have inserted element at start so making x as head
    if (cnt == 0)
    {
        head = &x;
    }

    //for iteration from start of list
    next = head;

    //result
    while (next != NULL)
    {
        printf("%d\n", next->num);
        next = next->next_node;
    }

    return 0;
}