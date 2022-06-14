/* Write a C program to implement STACK operations using array

Test Cases:
example 1:
input = 1 
12 
1 
21 
1 
45 
3 
4
output = 45 21 12

example 2:
case = t2
input = 2
4
output = stack is empty
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int stack[SIZE];
int top=-1;

void push();
void pop();
void display();

void main()
{
    int ch;
    while(1)
    {
        scanf ("%d",&ch);
        switch(ch)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nInvalid choice!!");
        }
    }
}

/*PUSH Function*/
void push()
{
    int x;
    if(top==SIZE-1)
        printf("stack is full");
    else
    {
        scanf ("%d",&x);
        top=top+1;
        stack[top]=x;
    }
}

/*POP Function*/
void pop()
{
    if(top==-1)
        printf("stack is empty");
    else
    {
        printf("%d is popped from stack\n",stack[top]);
        top=top-1;
    }
}

/*Function to DISPLAY Stack*/
void display()
{
    int i;
    if(top==-1)
        printf("stack is empty");
    else
    {
        for(i=top; i>=0; --i)
        {
            printf("%4d",stack[i]);
        }
    }
}