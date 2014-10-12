#include"stackfunc.h"
Error Error_stack ;
stack *constructor(int Size)
{
    stack *my_stack=(stack*)malloc((1) * (sizeof(stack)));
    if (my_stack)
    {
        my_stack->data = (int*)malloc((Size) * sizeof(int));
        if (my_stack->data!=0)
        {
            my_stack->Max = Size;
            my_stack->size = 0;
            my_stack->top = my_stack->data[0];
        }
        return my_stack;
    }
    else
        return 0;

}
// delete stack
int Destroy(stack *my_stack)
{
    free(my_stack->data);
}
// get stack_size
int stack_size(stack *my_stack)
{
    return my_stack-> size;
}

// add element
int push (stack *my_stack, int i)
{
     my_stack->Exist_of_error = 0;
    Stack_OK(my_stack);
    if ((!my_stack->Exist_of_error)||(Error_stack.stack_push_pop))
    {
        Error_stack.stack_push_pop = 0;
        my_stack->data[(my_stack->size)++] = i;
        my_stack->top = my_stack->data[i];
    }
    else
        Stack_dump(my_stack, Error_stack);
}

// delete element
int pop(stack *my_stack)
{
    my_stack->Exist_of_error = 0;
    Stack_OK(my_stack);
    if (my_stack->Exist_of_error == 0)
        {
            return my_stack->data[--my_stack->size];
        }
    else
        Stack_dump(my_stack,Error_stack);
}
//show last element
int topp(stack *my_stack)
{
    my_stack->Exist_of_error = 0;
    Stack_OK(my_stack);
    if (!my_stack->Exist_of_error)
        return my_stack->top;
    else
        Stack_dump(my_stack, Error_stack);
    return 0;
}
// clear stack
int clear(stack *my_stack)
{
    my_stack->Exist_of_error = 0;
    Stack_OK(my_stack);
    if (my_stack->Exist_of_error)
        Stack_dump(my_stack, Error_stack);
    else
        {
            while (my_stack->size > 0)
            pop(my_stack);
        }
}
// does error exist;

// check stack
int Stack_OK(stack *my_stack)
{

    if (!my_stack)
        {
            Error_stack.stack_undefinded = -1;
            my_stack->Exist_of_error  = -1;
        }
    if (my_stack->size < 0)////overflow
        {
             Error_stack.stack_size_negative = -2;
             my_stack->Exist_of_error  = -1;
        }
    if (my_stack->size >= my_stack->Max)
        {
            Error_stack.stack_size_big = -3;
            my_stack->Exist_of_error  = -1;
        }

    if (!my_stack->size)// stack empty
        {
            Error_stack.stack_push_pop = -4;
            my_stack->Exist_of_error  = -1;
        }
    return my_stack->Exist_of_error ;
}
int Stack_dump(stack *my_stack,Error Error_stack)
{
    if (Error_stack.stack_undefinded)
    {
        printf ("ERROR:YOU HAVEN'T STACK");
    }

    if (Error_stack.stack_size_negative)
       {
            printf ("ERROR:NATURAL NUMBER IS NEGATIVE");
       }
    if (Error_stack.stack_size_big)
        {
            printf("ERROR:YOUR STACK IS VERY BIG");
        }
    if (Error_stack.stack_push_pop!=0)
        {
            printf("ERROR: YOU HAVEN'T ELEMENTS IN STACK");
        }
}
