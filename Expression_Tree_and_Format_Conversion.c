#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

/* creating node for tree */
struct tree_node
{
    char data;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
};

typedef struct tree_node tr_nd;

/* node for stack which can store address of tree node*/
struct stack_node
{
    tr_nd *item;
    struct stack_node *next;
};

typedef struct stack_node stk_nd;

/* Funtion to push tree node in stack */
stk_nd *push(stk_nd *node, tr_nd *data)
{
    stk_nd *n = (stk_nd *)malloc(sizeof(stk_nd));
    if (n == NULL) //checking main stack is full or not
    {
        printf("Stack is FULL\n");
        return node;
    }
    n->item = data;
    n->next = node;
    return n;
}

/* Function to pop out top element of the stack */
stk_nd *pop(stk_nd *node)
{
    stk_nd *temp = node;
    node = node->next;
    free(temp); //free space
    return node;
}

/*Function to show top element of the stack */
tr_nd *top(stk_nd *head)
{
    return head->item;
}

/* inorder traversal in tree */
void inorder(tr_nd *root)
{
    if (root == NULL) //base condition
        return;

    /* giving parenthesis before operator along with expression */
    if (root->left != NULL && root->right != NULL)
    {
        printf("(");
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);

    /* giving parenthesis after operator along with expression */
    if (root->left != NULL && root->right != NULL)
    {
        printf(")");
    }
}

/* preorder traversal */
void preorder(tr_nd *root)
{
    if (root == NULL)
        return;

    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    stk_nd *head = NULL; //empty expression tree
    tr_nd *root = NULL;  //empty stack of tree node's address

    //for input
    char expression[500];
    gets(expression);

    //goiing for each character
    for (int i = 0; i < strlen(expression); i++)
    {
        char current_char = expression[i];

        /* if current char is operant then by creating 
        null node of tree having current char as data and pushing it in stack */
        if (current_char >= 97 && current_char <= 122)
        {
            tr_nd *n = (tr_nd *)malloc(sizeof(tr_nd));
            n->left = NULL;
            n->right = NULL;
            n->parent = NULL;
            n->data = current_char;
            head = push(head, n);
        }
        /* if current char is operator then by creating null node and then
        right of node as top of stack and left node as next top of stack then by poping out
        this two stack element, pushing this new node of tree in stack */
        else
        {
            tr_nd *n = (tr_nd *)malloc(sizeof(tr_nd));

            if (head == NULL) //cheking valid or not
            {
                printf("Error\n");
                exit(1);
            }
            n->data = current_char;
            n->right = top(head);
            head = pop(head);

            if (head == NULL) //cheking valid or not
            {
                printf("Error\n");
                exit(1);
            }
            n->left = top(head);
            head = pop(head);
            head = push(head, n);
        }
    }

    /* creating root for the tree */
    root = top(head);
    inorder(root); //result 1
    printf("\n");
    preorder(root); //result 2
    return 0;
}