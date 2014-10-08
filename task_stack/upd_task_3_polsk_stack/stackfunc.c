#include"stackfunc.h"
// create stack
stack *constructor(int Size, int type)
{
    stack *my_stack=malloc((Size) * (type));
    my_stack->data = malloc((Size) * (type));
    if (my_stack->data!=0)
    {
        my_stack->MAX_SIZE=Size;
        my_stack->size = 0;
        my_stack->top = my_stack->data;
    }
    return my_stack;
}

// delete stack
void Delete(stack *my_stack)
{
    free(my_stack->data);
}
// получить размер стека
int  stack_size(stack *my_stack)
{
    return my_stack-> size;
}
//overflow
int full(stack *my_stack)
{
    if (my_stack->size > my_stack->MAX_SIZE)
    return -1;
}
// add element
void push (stack *my_stack, int i)
{
    if (full(my_stack) == -1)
    {
        printf("ERROR");
    }
    else
    {
        my_stack->data[(my_stack->size)++] = i;//вставить и  увеличить стек
        my_stack->top = i;
    }
}
//is empty
int empty(stack *my_stack)
{
    if (!my_stack->size)
        return 0;
}
// delete element
int pop(stack *my_stack)
{
   if (empty(my_stack))
       return my_stack->data[--my_stack->size];
    else
        return 0;
}

//show last element
int top(stack *my_stack)
{
    if (empty(my_stack))
     return my_stack->top;
    else
        printf("ERROR");
        return 0;
}
// clear stack
void clear(stack *my_stack)
    {
        while (my_stack->size > 0)
            pop(my_stack);
    }
