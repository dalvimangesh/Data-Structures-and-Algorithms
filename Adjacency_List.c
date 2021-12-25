#include <stdio.h>
#include <malloc.h>

/* creating singly linked list */
struct node
{
    int item;
    struct node *next;
};
typedef struct node node;

/*Function to insert node in linked list of given vertex*/
node *insert(node *cur_node, int data)
{
    /* Creating node with given data */
    node *new = (node *)malloc(sizeof(node));

    if (new == NULL) // checking stack is full or not
    {
        printf("Stack Overflow\n");
        return cur_node;
    }

    //giving value to created node
    new->item = data;
    new->next = NULL;

    /* if linked list is empty then we can 
    simply replace current head with created node */
    if (cur_node == NULL)
    {
        return new;
    }

    /* storing head pointer */
    node *head = cur_node;

    /* going for last element then
    correcting it to new node */
    while (cur_node->next != NULL)
    {
        cur_node = cur_node->next;
    }
    cur_node->next = new;

    /* head will not change */
    return head;
}

/* Function to printing all elements of given linked list */
void PrintNode(node *node)
{
    /* linked list is empty */
    if (node == NULL)
    {
        printf("Nil\n");
        return;
    }

    /* going for each element */
    while (node != NULL)
    {
        if (node->next == NULL)
        {
            printf("%d\n", node->item);
            return;
        }
        printf("%d ", node->item);
        node = node->next;
    }
    return;
}

/* Function to print vertexes connected to current vertex */
void PrintGraph(node *graph[], int n)
{
    for (int i = 0; i < n; i++)
    {
        PrintNode(graph[i]);
    }
}

int main()
{
    /*Input for No of vertex and no of edges*/
    int n, edges;
    scanf(" %d %d", &n, &edges);

    /* Creating empty graph */
    node *graph[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = NULL;
    }

    //input for edges
    int v1, v2;
    while (edges--)
    {
        scanf(" %d", &v1);
        scanf(" %d", &v2);
        //inserting v2 in linked list of vertex of v1
        graph[v1] = insert(graph[v1], v2);

        //inserting v1 in linked list of vertex of v2
        graph[v2] = insert(graph[v2], v1);
    }

    //result
    PrintGraph(graph, n);
    return 0;
}