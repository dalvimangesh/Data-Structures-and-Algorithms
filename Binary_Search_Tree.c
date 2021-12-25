#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* creating node for BST */
struct node
{
    int item;
    struct node *left;
    struct node *parent;
    struct node *right;
};

typedef struct node node;

/* checking memory is full or not */
bool ispossible()
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
        return false;
    free(temp);
    return true;
}

/*Function to create empty node for given number */
node *create_node(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->left = NULL;
    n->parent = NULL;
    n->right = NULL;
    n->item = data;
    return n;
}

/* Function to insert element in BST at its correct position*/
node *insert(node *cur_node, int data)
{
    if (cur_node == NULL) //empty BST
    {
        return create_node(data);
    }

    node *temp = NULL;

    if (data < cur_node->item)
    {
        temp = insert(cur_node->left, data); // our element will be left sub tree
        cur_node->left = temp;
        temp->parent = cur_node;
    }
    else
    {
        temp = insert(cur_node->right, data); // our element will be right sub tree
        cur_node->right = temp;
        temp->parent = cur_node;
    }

    return cur_node;
}

/* Function to search element in BST */
bool search(node *cur_node, int data)
{
    if (cur_node == NULL)
    {
        return false;
    }

    if (data == cur_node->item)
    {
        return true;
    }

    if (data < cur_node->item)
    {
        search(cur_node->left, data); // our element will be left sub tree
    }
    else
    {
        search(cur_node->right, data); // our element will be right sub tree
    }
}

/* Function for inorder traversal */
void inorder(node *cur_node)
{
    if (cur_node == NULL)
        return;
    inorder(cur_node->left);
    printf("%d\n", cur_node->item);
    inorder(cur_node->right);
}

/* Function for preorder traversal */
void preorder(node *cur_node)
{
    if (cur_node == NULL)
        return;
    printf("%d\n", cur_node->item);
    preorder(cur_node->left);
    preorder(cur_node->right);
}

/* Function for postorder traversal */
void postorder(node *cur_node)
{
    if (cur_node == NULL)
        return;
    postorder(cur_node->left);
    postorder(cur_node->right);
    printf("%d\n", cur_node->item);
}

/* Function to print successor of given element 
if given element dont have successor then it will return NULL*/
node *Successor(node *cur_root, node *sucser, int num)
{
    if (cur_root == NULL)
        return sucser;

    if (cur_root->item == num)
    {
        if (cur_root->right != NULL)
        {
            cur_root = cur_root->right;
            while (cur_root->left != NULL)
            {
                cur_root = cur_root->left;
            }
            return cur_root;
        }
    }

    else if (num < cur_root->item)
    {
        sucser = cur_root;
        return Successor(cur_root->left, cur_root, num);
    }

    else
    {
        return Successor(cur_root->right, sucser, num);
    }

    return sucser;
}

/* Function to print predecessor of given element 
if given element dont have predecessor then it will return NULL*/
node *Predecessor(node *cur_root, node *predcr, int num)
{
    if (cur_root == NULL)
        return predcr;

    if (cur_root->item == num)
    {
        if (cur_root->left != NULL)
        {
            cur_root = cur_root->left;
            while (cur_root->right != NULL)
            {
                cur_root = cur_root->right;
            }
            return cur_root;
        }
    }

    else if (num < cur_root->item)
    {
        return Predecessor(cur_root->left, predcr, num);
    }

    else
    {
        predcr = cur_root;
        return Predecessor(cur_root->right, cur_root, num);
    }

    return predcr;
}

int main()
{
    node *root = NULL; // Empty BST

    while (true)
    {
        // input for function calls
        int n = -1;
        scanf(" %d", &n);

        // inserting element if possible
        if (n == 1)
        {
            int element = 0;
            scanf(" %d", &element);
            if (ispossible())
            {
                root = insert(root, element);
            }
            else
            {
                printf("Insert Fail\n");
            }
        }

        //checking element is present in BST or not
        if (n == 2)
        {
            int element = 0;
            scanf(" %d", &element);
            bool find = search(root, element);
            if (find)
            {
                printf("Found\n");
            }
            else
            {
                printf("Not Found\n");
            }
        }

        if (n == 3) // inorder traversal
        {
            inorder(root);
        }

        if (n == 4) //preorder traversal
        {
            preorder(root);
        }

        if (n == 5) //postorder traversal
        {
            postorder(root);
        }

        if (n == 6) //Predecessor of given element
        {
            int element = 0;
            scanf(" %d", &element);

            // checking element is present in tree or not
            bool find = search(root, element);
            if (find == false)
            {
                printf("Invalid Input\n");
                continue;
            }
            node *temp = Predecessor(root, NULL, element);
            if (temp == NULL) //No predecessor
            {
                printf("No predecessor\n");
            }
            else
            {
                printf("%d\n", temp->item);
            }
        }

        if (n == 7)
        {
            int element = 0;
            scanf(" %d", &element);

            // checking element is present in tree or not
            bool find = search(root, element);
            if (find == false)
            {
                printf("Invalid Input\n");
                continue;
            }
            node *temp = Successor(root, NULL, element);
            if (temp == NULL) // No successor
            {
                printf("No successor\n");
            }
            else
            {
                printf("%d\n", temp->item);
            }
        }

        if (n == 8) //exiting loop
        {
            break;
        }
    }

    return 0;
}