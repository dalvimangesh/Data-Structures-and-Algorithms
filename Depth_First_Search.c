#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// to store entry time for given vertex
int Entry[5000];

// to store exit time for given vertex
int Exit[5000];

//to store given vertex is visited or not
bool visited[5000];

//to store current time
int clock = 0;

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

/* Function for visiting all vertexes attached to current vertex */
void DFS_Explore(node *graph[], int value)
{
    //current vertex is visited
    visited[value] = true;

    Entry[value] = clock; //entry time
    clock++;
    node *itr = graph[value];

    //if there is no vertex attached to current vertex */
    if (itr == NULL)
    {
        Exit[value] = clock;
        clock++;
        return;
    }

    /* going for all vertex attached to current vertex */
    while (itr != NULL)
    {
        if (!visited[itr->item])
        {
            DFS_Explore(graph, itr->item);
        }
        itr = itr->next;
    }

    Exit[value] = clock; //exit time
    clock++;
    return;
}

/* Function to explore dfs for 
current vertexx if it is not visited */
void DFS(node *graph[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS_Explore(graph, i);
        }
    }
}

int main()
{
    /*Input for No of vertex and no of edges*/
    int n, edges;
    scanf(" %d %d", &n, &edges);

    /* creating empty graph */
    node *graph[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = NULL;
    }

    /* input for edges */
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

    /* space for int from which we first do dfs */
    int value;
    scanf(" %d", &value);

    // calling to dfs explore for given value
    DFS_Explore(graph, value);

    // using dfs explore for non visited vertex
    DFS(graph, n);

    //result
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", Entry[i], Exit[i]);
    }

    return 0;
}