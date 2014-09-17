#include<stdio.h>

double sum(double a, double b)
{
    return a+b;
}

double umnoz(double a, double b)
{
    return a*b;
}

double raznost(double a, double b)
{
    return a-b;
}

double del(double a, double b)
{
    return a/b;
}

int main()
{
    char c=0;
    double a=0,b=0;
    scanf("%lf\n%c\n%lf",&a,&c,&b);
    switch(c){
    case '+':
        printf("=\n%.2lf",sum(a,b));
     break;
    case '-':
        printf("=\n%.2lf",raznost(a,b));
     break;
    case '*':
        printf("=\n%.2lf",umnoz(a,b));
     break;
    case '/':
        printf("=\n%.2lf",del(a,b));
     break;
    }
    return(0);
}
