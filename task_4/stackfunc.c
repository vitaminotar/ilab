#include"stackfunc.h"
#include<errno.h>
#include<math.h>
#include<stdio.h>
#include<stddef.h>
#define DEBUGSTYACK
stack *Stack_Constructor(int Size)
{
    stack *my_stack=(stack*)malloc((1) * (sizeof(stack)));
    if (my_stack)
    {
        my_stack->data = (int*)malloc((Size) * sizeof(double));
        if (my_stack->data!=NULL)
        {
            my_stack->Max = Size;
            my_stack->size = 0;
            my_stack->top = my_stack->data[0];
            return my_stack;
        }
        else
        {
            errno = ENOMEM;
            return NULL;
        }
    }
    else
    {
        errno = ENOMEM;
        return NULL;
    }

}
// check stack
int Stack_OK(stack *my_stack)
{

    if (!my_stack)
        {
            errno = EFAULT;
            return -1;
        }
    if (my_stack->size < 0)
        {
             errno = EINVAL;
             return -1;
        }
    if (!my_stack->data)
        {
            errno = EAGAIN;
            return -1;
        }
    if (my_stack->size >= my_stack->Max)
        {
            errno = EACCES;
            return -1;
        }
    errno = 0;
    return 0;
}
// delete stack
int Destroy(stack *my_stack)
{

    if (Stack_OK(my_stack))
        return -1;
    free(my_stack->data);
    free(my_stack);
    errno = 0;
    return 0;
}
// get stack_size
int stack_size(stack *my_stack)
{
    if(Stack_OK(my_stack))
        return -1;
    return my_stack->size;
}


// add element
int push (stack *my_stack, double i)
{
    Stack_OK(my_stack);
    if (!full(my_stack))
    {
        my_stack->data[(my_stack->size)++] = i;
        my_stack->top = i;
        Stack_OK(my_stack);
        return 0;
    }
    else
        errno = E2BIG;
    return -1;

}

// delete element
double pop(stack *my_stack)
{
    errno = 0;
    Stack_OK(my_stack);
    if ((!errno) && (!empty(my_stack)))
        {
            return my_stack->data[--my_stack->size];
        }
    else
        return NAN;
}
//show last element
double topp(stack *my_stack)
{
     errno = 0;
    Stack_OK(my_stack);
    if (!errno)
        return my_stack->top;
    else
        Stack_dump(my_stack);
    return -1;
}
// clear stack
int clear(stack *my_stack)
{
    Stack_OK(my_stack);
    if (Stack_OK(my_stack))
        Stack_dump(my_stack);
    else
        {
            my_stack->data = 0;
            errno = 0;
            return 0;
        }
    return -1;
}
// does error exist;
int empty(stack *my_stack)
{
    if(my_stack->size == 0)
        return -1;
    else
        return 0;
}

int full(stack *my_stack)
{
    if (Stack_OK(my_stack))
        Stack_dump(my_stack);
    if(my_stack->size == my_stack->Max)
        return -1;
    else
        return 0;
}
int Stack_dump(stack *my_stack)
{
    int DEB_G = -1;
    #ifdef DEBUGSTYACK
    DEB_G = 1;
    #else
    DEB_G = 0;
    #endif;
   if (DEB_G)
   {
        FILE *fp;
        fp = fopen("dump.txt","w");
        int i = 0;
        if (!empty(my_stack))
        {
            while(my_stack->size--)
            {
                fprintf(fp,"%lf",pop(my_stack));
            }
        }
        switch errno{
            case ENOMEM:
                fprintf(fp,"No memory");
                break;
            case EACCES:
                fprintf(fp,"Access denial");
                break;
            case EDOM:
                fprintf(fp,"Division by zero");
                break;
            case EFAULT:
                fprintf(fp,"Stack adress is wrong");
                break;
            case EAGAIN:
                fprintf(fp,"No memory in stack");
                break;
            case EINVAL:
                fprintf(fp,"Stack head is not a vailiable");
                break;
            case E2BIG:
                fprintf(fp,"Stack is very big1");
                break;
            default:
                fprintf(fp,"Unknown error");
                break;
        }
        fclose(fp);
   }
}

