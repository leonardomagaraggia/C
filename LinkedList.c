//Magraggia Leonardo    LinkedList.c 2022

#include <stdio.h>
#include <stdlib.h>


struct node
{
    char * value;
    struct node * nextNode;
};

typedef struct node Node;
typedef struct node * listaNode;

void printList(listaNode list);
void aggiungiNodo(listaNode * list,char * elemento);
void aggiungiCoda(listaNode * list,char * elemento);
int indexOf(listaNode list,char * elemento);
void printListReverse(listaNode list);

int main()
{
    //Example code
    listaNode list = NULL;

    aggiungiNodo(&list,"Mario Rossi");
    aggiungiNodo(&list,"Lampa Dario");
    aggiungiCoda(&list,"Leonardo Da Vinci");

    printList(list);

    printf("POSIZIONE %s: %d","Leonardo Da Vinci",indexOf(list,"Leonardo Da Vinci"));

    printf("\n");
    return 0;
}


void aggiungiNodo(listaNode * list,char * elemento)
{
    Node * nodo = (Node*)malloc(sizeof(Node));
    if(!nodo)
        exit(1);
    nodo->value = elemento;
    nodo->nextNode = *list;
    *list = nodo;
}

void aggiungiCoda(listaNode * list,char * elemento)
{
    if(!*list)
    {
        Node * nodo = (Node*) malloc(sizeof(Node));
        if(!nodo)
            exit(1);
        nodo->value = elemento;
        nodo->nextNode = NULL;
        *list = nodo;
    }
    else{
        aggiungiCoda(&((*list)->nextNode),elemento);
    }

}

int indexOf(listaNode list,char * elemento)
{
    if(list)
    {
        if(list->value == elemento)
        {
            indexOf(list->nextNode,elemento);
            return 0;
        }
        else
        {
            return 1 + indexOf(list->nextNode,elemento);
        }
    }
    else
        return -1;
}


void printList(listaNode list){
    
    if(list != NULL)
    {
        printf("Elemento: %s\n",list->value);
        printList(list->nextNode);
    }
}

void printListReverse(listaNode list){
    
    if(list != NULL)
    {
        printList(list->nextNode);
        printf("Elemento: %s\n",list->value);
    }
}