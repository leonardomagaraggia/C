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
    StackPtr *s = malloc(sizeof(Stack));

    int number1 = 8;
    int number2 = 10;
    int number3 = 20;

    push(s,&number1);
    push(s,&number2);
    push(s,&number3);


    printf("POP result : %d\n",*((int *)(pop(s))));
    printf("POP result : %d\n",*((int *)(pop(s))));
    printf("POP result : %d\n",*((int *)(pop(s))));

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
    void * elementPopped = (*stack)->pointer;
    *stack = (*stack)->previous;
    return elementPopped;
}