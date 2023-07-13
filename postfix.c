#include <stdio.h>
int prio(char m)//This function will get the priority of the symbol
{
    int p;
    if(m=='+'||m=='-')
        p=2;
    else if(m=='*'||m=='/')
        p=3;
    else if(m=='^')
        p=4;
    else if(m=='(')
        p=5;
    else 
        p=1;
    return p;
}
void main()
{
    printf("Enter the expression");
    char a[30];
    scanf("%s",a);
    char e[30];
    e[0]='(';
    int i=0;
    while(a[i]!='\0')
    {   e[i+1]=a[i];
        i++;
    }
    i++;
    e[i++]=')';
    int l=i;char n[30];int t=0;char s[30];int f=0;int pr[30];//s is the stack that stores symbols,pr stores priority of those symbols
    s[0]='(';
    pr[0]=5;
    for(i=1;i<l;i++)
    {   char em=e[i];
        if(em=='+'||em=='-'||em=='*'||em=='/'||em=='^'||em=='('||em==')')
        {   int p=prio(em);
            if(p<=pr[f]&&!(pr[f]==4&&p==4))       
            {    while(p<=pr[f]&&!(pr[f]==4&&p==4))
                {   if(pr[f]==5&&p==1)
                        {f--;break;}
                    else if(pr[f]==5)
                        break;
                    else
                        n[t++]=s[f--];
                }
                if(p!=1)
                {   s[++f]=em;
                    pr[f]=p;
                }
            }
            else
            {   s[++f]=em;
                pr[f]=p;
            }
        }
        else
            n[t++]=em;
    }
    for(int j=0;j<t;j++)
        printf("%c",n[j]);
    printf("\n");
}