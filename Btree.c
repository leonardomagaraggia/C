// Magaraggia Leonardo Btree.h 12/2022
#include <stdio.h>
#include <stdlib.h>

struct Btree
{
    char key;
    struct Btree *p;
    struct Btree *sx;
    struct Btree *dx;
};

typedef struct Btree Btree;
typedef Btree *BtreePtr;

void printOrder(BtreePtr tree)
{
    // stampa simmetrica dei nodi
    if (tree != NULL)
    {
        printOrder(tree->sx);
        printf("%c ", tree->key);
        printOrder(tree->dx);
    }
}

void printPreOrder(BtreePtr tree)
{
    // stampa in preordine dei nodi
    if (tree != NULL)
    {
        printf("%c ", tree->key);
        printPreOrder(tree->sx);
        printPreOrder(tree->dx);
    }
}

void printPostOrder(BtreePtr tree)
{
    // stampa post ordinata dei nodi
    if (tree != NULL)
    {
        printPostOrder(tree->sx);
        printPostOrder(tree->dx);
        printf("%c ", tree->key);
    }
}

BtreePtr searchTree(BtreePtr tree, char key)
{
    if (tree == NULL || tree->key == key)
        return tree;

    if (tree->key < key)
        return searchTree(tree->sx, key);
    else
        return searchTree(tree->dx, key);
}

BtreePtr treeMinimum(BtreePtr tree)
{
    while (tree->sx != NULL)
    {
        tree = tree->sx;
    }

    return tree;
}

BtreePtr treeMaximum(BtreePtr tree)
{
    while (tree->dx != NULL)
    {
        tree = tree->dx;
    }

    return tree;
}

BtreePtr successor(BtreePtr tree)
{
    if (tree->dx != NULL)
        return treeMinimum(tree->dx);

    BtreePtr y = tree->p;
    while (y != NULL && tree == y->dx)
    {
        tree = y;
        y = tree->p;
    }
    return y;
}

BtreePtr predecessor(BtreePtr tree)
{
    if (tree->sx != NULL)
        return treeMaximum(tree->sx);

    BtreePtr y = tree->p;
    while (y != NULL && tree == y->sx)
    {
        tree = y;
        y = tree->p;
    }
    return y;
}

char max(char c1, char c2)
{
    if (c1 > c2)
    {
        return c1;
    }
    else
        return c2;
}

int getHeigth(BtreePtr tree)
{
    if (tree != NULL)
    {
        int leftHeigth = getHeigth(tree->sx);
        int rightHeigth = getHeigth(tree->dx);
        return max(leftHeigth, rightHeigth) + 1;
    }
    return -1;
}

BtreePtr createNode(char key)
{
    BtreePtr tree = (BtreePtr)malloc(sizeof(Btree));
    tree->key = key;
    tree->dx = tree->sx = NULL;

    return tree;
}

void insertRic(BtreePtr *tree, BtreePtr *node)
{
    if ((*node)->key < (*tree)->key)
    {
        if ((*tree)->sx == NULL)
        {
            (*tree)->sx = *node;
            (*node)->p = *tree;
        }
        else
            insertRic(&(*tree)->sx, node);
    }
    else
    {
        if ((*tree)->dx == NULL)
        {
            (*tree)->dx = *node;
            (*node)->p = *tree;
        }
        else
            insertRic(&(*tree)->dx, node);
    }
}

void insert(BtreePtr *tree, BtreePtr *node)
{
    if (*tree == NULL)
    {
        *tree = *node;
        (*node)->p = NULL;
    }
    else
        insertRic(tree, node);
}

int main()
{
    system("clear");
    printf("MAGARAGGIA LEONARDO - ALBERI BINARI ORDINATI IN C\n\n");

    BtreePtr albero = (BtreePtr)malloc(sizeof(Btree));

    int nElem;
    printf("Quanti Elementi vuoi iserire nell'albero? : ");
    scanf("%d", &nElem);
    printf("\n");

    do
    {
        char elem[2];
        printf("\nInserisci elemento: ");
        scanf("%1s", elem);

        BtreePtr nodo = createNode(elem[0]);
        insert(&albero, &nodo);

    } while (--nElem > 0);

    printf("\nAlbero ordinato simmetricamente: ");
    printOrder(albero);

    printf("\nAlbero in preordine: ");
    printPreOrder(albero);

    printf("\nAlbero in postordine: ");
    printPostOrder(albero);

    printf("\nAltezza albero: %d", getHeigth(albero));

    printf("\n");
    return 0;
}