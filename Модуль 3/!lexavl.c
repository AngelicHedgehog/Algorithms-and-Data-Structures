#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node
{
    int value, balance;
    unsigned long key;
    Node *parent, *left, *right;
};

typedef struct Tree
{
    Node *root;
} Tree;

Node *tree_find_node(Tree *tree, unsigned long key)
{
    Node *node = tree->root;

    while (node && node->key != key)
    {
        if (key < node->key) node = node->left;
        else node = node->right;
    }
    return node;
}

void tree_insert_node(Tree *tree, unsigned long key, int value)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->parent = NULL; new_node->left = NULL; new_node->right = NULL;
    new_node->key = key;
    new_node->value = value;
    new_node->balance = 0;

    if (!tree->root)
    {
        tree->root = new_node;
        return;
    }

    Node *node = tree->root;
    for (;;)
    {
        if (key < node->key)
        {
            if (node->left == NULL)
            {
                node->left = new_node;
                new_node->parent = node;
                break;
            }
            node = node->left;
        }
        else
        {
            if (node->right == NULL)
            {
                node->right = new_node;
                new_node->parent = node;
                break;
            }
            node = node->right;
        }
    }

}

Tree *tree_replace_node(Tree *tree, Node *x, Node *y)
{
    if (x == tree->root)
    {
        tree->root = y;
        if (y != NULL) y->parent = NULL;
    }
    else
    {
        Node *p = x->parent;
        if (y != NULL) y->parent = p;
        if (p->left == x) p->left = y;
        else p->right = y;
    }
    return tree;
}

void tree_clear_node(Node *node)
{
    if(node)
    {
        if(node->left) tree_clear_node(node->left);
        if(node->right) tree_clear_node(node->right);
        free(node);
    }
}

void tree_clear(Tree *tree)
{
    if(tree->root)
        tree_clear_node(tree->root);
}

Node *avl_tree_rotate_left(Tree *tree, Node *x)
{
    Node *y = x->right;
    tree_replace_node(tree, x, y);
    Node *b = y->left;

    if(b) b->parent = x;
    x->right = b;
    x->parent = y;
    y->left = x;

    x->balance--;
    if(y->balance > 0)
        x->balance = x->balance - y->balance;

    y->balance--;
    if(x->balance < 0)
        y->balance = y->balance + x->balance;
}

Node *avl_tree_rotate_right(Tree *tree, Node *x)
{
    Node *y = x->left;
    tree_replace_node(tree, x, y);
    Node *b = y->right;

    if(b) b->parent = x;
    x->left = b;
    x->parent = y;
    y->right = x;

    x->balance++;
    if(y->balance < 0)
        x->balance = x->balance - y->balance;

    y->balance++;
    if(x->balance > 0)
        y->balance = y->balance + x->balance;
}

Node *avl_tree_insert_node(Tree *tree, unsigned long key, int value)
{
    tree_insert_node(tree, key, value);

    Node *a = tree->root;
    a->balance = 0;
    Node *x = a->parent;

    for (;;)
    {
        x = a->parent;
        if (!x) break;
        if (a == x->left)
        {
            x->balance--;
            if (x->balance == 0) break;
            if (x->balance == -2)
            {
                if (a->balance == 1) avl_tree_rotate_left(tree, a);
                avl_tree_rotate_right(tree, x);
                break;
            }
        }
        else
        {
            x->balance++;
            if (x->balance == 0) break;
            if (x->balance == 2)
            {
                if (a->balance == -1) avl_tree_rotate_right(tree, a);
                avl_tree_rotate_left(tree, x);
                break;
            }
        }
    }
    return a;
}

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while(c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}

#define CLEAR\
            if (len_ident)\
            {\
                ident[len_ident] = '\0';\
                unsigned long word_hash = hash(ident);\
                int found = tree_find_node(&tree, word_hash) != NULL;\
                if(!found)\
                    avl_tree_insert_node(&tree, word_hash, current_ident_id++);\
                printf("IDENT %d\n", tree_find_node(&tree, word_hash)->value);\
                len_ident = 0;\
            }\
            else if (cnst != -1)\
            {\
                printf("CONST %d\n", cnst);\
                cnst = -1;\
            }

int main(int argc, char **argv)
{
    int n, cnst = -1, len_ident = 0, current_ident_id = 0, i, j;
    char *spec = "+-*/()", symbol;
    scanf("%d", &n);
    char ident[n]; fgetc(stdin);

    Tree tree;
    tree.root = NULL;

    for (; n; n--)
    {
        symbol = fgetc(stdin);

        if (('a' <= symbol && symbol <= 'z') || ('A' <= symbol && symbol <= 'Z'))
            ident[len_ident++] = symbol;
        else if ('0' <= symbol && symbol <= '9')
        {
            if (len_ident)
                ident[len_ident++] = symbol;
            else if (cnst == -1)
                cnst = symbol - '0';
            else
                cnst = cnst * 10 + (symbol - '0');
        }
        else
        {
            CLEAR
            for (i=0; i<6; i++)
                if (symbol == spec[i])
                    printf("SPEC %d\n", i);
        }
    }
    CLEAR;
    tree_clear(&tree);
    return 0;
}

