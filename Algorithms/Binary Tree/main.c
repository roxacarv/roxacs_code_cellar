#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT {
    int data;
    struct NodeT * left;
    struct NodeT * right;
    struct NodeT * parent;
} Node;

typedef struct BinaryTreeT {
    char * name;
    int size;
    struct NodeT * root;
} BinaryTree;

struct BinaryTreeT * create_tree(char * name);
struct BinaryTreeT * add_node(BinaryTree * binaryTree, int data);
void print_post_order(Node * current);
void print_in_order(Node * current);
void print_pre_order(Node * current);

struct BinaryTreeT * create_tree(char * name)
{
    BinaryTree * new_tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    new_tree->size = 0;
    new_tree->name = name;
    new_tree->root = NULL;
    return new_tree;
}

struct BinaryTreeT * add_node(BinaryTree * binaryTree, int data)
{
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if(!binaryTree->root)
    {
        new_node->parent = NULL;
        binaryTree->root = new_node;
        binaryTree->size++;
        return binaryTree;
    }
    Node * current_node = binaryTree->root;
    while(current_node)
    {
        if((new_node->data) < (current_node->data))
        {
            if(!current_node->left)
            {
                new_node->parent = current_node;
                current_node->left = new_node;
                binaryTree->size++;
                break;
            }
            current_node = current_node->left;
        }

        if((new_node->data) > (current_node->data))
        {
            if(!current_node->right)
            {
                new_node->parent = current_node;
                current_node->right = new_node;
                binaryTree->size++;
                break;
            }
            current_node = current_node->right;
        }
    }
    return binaryTree;
}

void print_post_order(Node * current)
{
    if(current == NULL)
        return;
    print_post_order(current->left);
    print_post_order(current->right);
    printf("%d ", current->data);
}

void print_in_order(Node * current)
{
    if(current == NULL)
        return;
    print_post_order(current->left);
    printf("%d ", current->data);
    print_post_order(current->right);
}

void print_pre_order(Node * current)
{
    if(current == NULL)
        return;
    printf("%d ", current->data);
    print_post_order(current->left);
    print_post_order(current->right);
}

int main()
{
    BinaryTree * btree = create_tree("Binary 1");
    btree = add_node(btree, 13);
    btree = add_node(btree, 11);
    btree = add_node(btree, 12);
    print_in_order(btree->root);
    print_pre_order(btree->root);
    print_post_order(btree->root);
    return 0;
}
