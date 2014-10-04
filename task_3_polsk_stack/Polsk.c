#include<stdio.h>
#include<malloc.h>
#include "structcreator.h"
#include "calcul.h"

int main()
{
    int x=0,a=0;
    char simvol;
    stack *stek_chisel = constructor(30, 4);

    while ((simvol = getchar())!='\n')
    {
        switch(simvol)
        {
            case ' ':
            case '+':
             add(stek_chisel);
             break;
            case '*':
             mul(stek_chisel);
             break;
            case '-':
             minus(stek_chisel);
             break;
            case '/':
             div(stek_chisel);
             break;
            default:
             x = simvol-'0';
             push(stek_chisel,x);
        }
    }
    a=pop(stek_chisel);
    printf("%d",a);
}
