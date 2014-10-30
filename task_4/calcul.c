#include<math.h>
#include "calcul.h"
#include<errno.h>
double add(stack *my_stack)
{
    double a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    push(my_stack,a+b);
}

double mul(stack *my_stack)
{
    double a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    push(my_stack, a*b);
}

double sub(stack *my_stack)
{
    double a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    push(my_stack, a-b);
}

double div(stack *my_stack)
{
    double a = 0,b = 0;
    a = pop(my_stack);
    b = pop(my_stack);
    if (!b)
    {
        errno = EDOM;
        Stack_dump(my_stack);
        return NAN;
    }
    else
    push(my_stack, a/b);
}
double SIN(stack *my_stack)
{
    double res = 0.0;
    res = sin(pop(my_stack));
    push(my_stack,res);
}

double COS(stack *my_stack)
{
    double res = 0.0;
    res = cos(pop(my_stack));
    push(my_stack,res);
}
double EXP(stack *my_stack)
{
    double res = 0.0;
    res = exp(pop(my_stack));
    push(my_stack,res);
}
double POW(stack *my_stack)
{
   double res = 0.0;
    res = pow(pop(my_stack),pop(my_stack));
    push(my_stack,res);
}
