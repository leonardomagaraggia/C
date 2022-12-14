//Magaraggia Leonardo stack.c 2022

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    void * pointer;
    struct Stack * previous;
};


typedef struct Stack Stack;
typedef struct Stack * StackPtr;


//Functions
void push(StackPtr * stack,void * ptr);
void * pop(StackPtr * stack);


int main()
{
    StackPtr *myStack = malloc(sizeof(Stack));

    //Example with different data types
    int intNumber = 42;
    char * name = "Leonardo";
    double doubleNumber = 12.921;
    push(myStack,&intNumber);
    push(myStack,name);
    push(myStack,&doubleNumber);

    printf("First POP: %.3f\n",*((double *)(pop(myStack))));
    printf("Second POP: %s\n",((char*)(pop(myStack))));
    printf("Third POP: %d\n",*((int *)(pop(myStack))));

    printf("\n");
    return 0;
}


void push(StackPtr * stack,void * ptr)
{
    StackPtr newElement = malloc(sizeof(Stack));
    newElement->pointer = ptr;
    newElement->previous = *stack;
    *stack = newElement;
}



void * pop(StackPtr * stack)
{
    if(!*stack)
        exit(1);
    void * elementPopped = (*stack)->pointer;
    StackPtr newTop = (*stack)->previous;
    free(*stack);
    *stack = newTop;
    return elementPopped;
}
