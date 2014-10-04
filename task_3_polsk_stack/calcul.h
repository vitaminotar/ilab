#ifndef calcul
#define calcul
int add(stack *my_stack)
{
    int a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    push(my_stack,a+b);
}

int mul(stack *my_stack)
{
    int a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    push(my_stack, a*b);
}

int minus(stack *my_stack)
{
    int a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    push(my_stack, a-b);
}

int div(stack *my_stack)
{
    int a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    if (b == 0)
        return *my_stack->ERR;
    else
    push(my_stack, a/b);
}
#endif
