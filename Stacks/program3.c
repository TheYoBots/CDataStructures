// C program to implement postfix evaluation.

#include<stdio.h>
#include<ctype.h>

#define STACK_SIZE 100

float stack[STACK_SIZE];
int top=-1;

void push(float[],float);
float pop(float[]);

void main()
{
    int i;
    float op1,op2,value,result;
    char exp[100];
    printf("Enter any postfix expression: ");
    scanf("%s",exp);
    for(i=0; exp[i]!='\0'; i++)
    {
        if(isdigit(exp[i]))
            push(stack,(float)(exp[i]-'0'));
        else
        {
            op2=pop(stack);
            op1=pop(stack);
            switch(exp[i])
            {
                case '+':value=op1+op2; break;
                case '-':value=op1-op2; break;
                case '/':value=op1/op2; break;
                case '*':value=op1*op2; break;
                case '%':value=(int)op1%(int)op2; break;
            }
            push(stack,value);
        }
    }
    result=pop(stack);
    printf("\nValue of the postfix expression=%.2f",result);
}

void push(float stack[],float val)
{
    if(top==STACK_SIZE-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        stack[top]=val;
    }
}

float pop(float stack[])
{
    float val;
    if(top==-1)
        printf("\nStack Underflow");
    else
    {
        val=stack[top];
        top--;
    }
    return val;
}