/* Write a C program to implement Postfix expresson Evaluation

case = t1
input = abc*+
1
2
3
output = The simplified answer for abc*+ =7

case = t2
input = abc/d*+
2 3 4 8
output = The simplified answer for abc/d*+ =11
*/

//Start writing program from here

#include <stdio.h>
#include <math.h>

#define MAX 50

int stack[MAX];
int top=-1;

void push(int);
int pop();
int isoperand(char);
int isoperator(char);

int main()
{
    char postfix[MAX],ch;
    int i=0,x,value,a,b,c;
    scanf("%s",postfix);
    for(i=0; postfix[i]!='\0'; i++)
    {
        ch=postfix[i];
        if(isoperand(ch))
        {
            scanf("%d",&x);
            push(x);
        }
        if(isoperator(ch))
        {
            a=pop();
            b=pop();
            switch(ch)
            {
                case '+': c=b+a;
                break;
                case '-': c=b-a;
                break;
                case '*': c=b*a;
                break;
                case '/': c=b/a;
                break;
                case '%': c=b%a;
                break;
                case '^': c=pow(b, a);
                break;
                default: printf("Invalid option");
            }
            push(c);
        }
    }
    value=pop();
    printf("\nThe simplified answer for %s =%d",postfix,value);
    return 0;
}

void push(int val)
{
    top++;
    stack[top]=val;
}

int pop()
{
    int k;
    k=stack[top];
    top--;
    return k;
}

int isoperand(char ch)
{
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
        return 1;
    else
        return 0;
}

int isoperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^')
        return 1;
    else
        return 0;
}