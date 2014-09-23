#include<stdio.h>

int proverka(char st[15],int i)
{

    if(((st[i+2]!='*')&& (st[i+2]!='/')&&(st[i+2]!='-')&&(st[i+2]!='+')))
    {
       return 0;
    }
    else
    {
       return 1;
    }
}

int znak(int b,int a,char c)
{
   switch (c)
        {
            case '+':
                return b+a;
             break;
            case '-':
               return b-a;
             break;
            case '*':
                return b*a;
             break;
            case '/':
                switch (a)
                {
                    case 0:
                    printf("eror");
                    break;
                    case !0:
                   return b/a;
                }

             break;
        }
}

int main()
{
    char st[15];
    char c;
    int otv=0,a=0,b=0,i=2,rez=0,f=0;
    gets(st);
    rez=st[0]-'0';
     while (st[i]!='\0')
    {
        int x=0;
        f=proverka(st,i);
        switch(f)
        {
            case 1:
                a=st[i]-'0';
                c=st[i+2];
                i=i+4;
                rez=znak(rez,a,c);
            break;
            case 0:

                a=st[i]-'0';
                b=st[i+2]-'0';
                c=st[i+4];
                x=znak(a,b,c);
                c=st[i+6];
                rez=znak(rez,x,c);
                i=i+8;
            break;
        }
    }
    printf("rezult=%d\n", rez);
}
