#include<stdio.h>


double cal(double a, char c)
    {

        double b=0,t=0;

        while(c!='=')
        {
            scanf("%lf",&b);
            switch(c){
            case '+':
                a=a+b;
             break;
            case '-':
                a=a-b;
             break;
            case '*':
                a=a*b;
             break;
            case '/':
                a=a/b;
             break;
            }
            scanf("%c",&c);

        }
        return a;
    }

    int main()
    {
        char c=0;
        double a=0,b=0,t=0;
        scanf("%lf\n%c\n",&a,&c);
        a=cal(a,c);
        printf("%lf",a);
        return(0);
    }
