// C program to implement stack with stack search.

#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int stack[SIZE];
int top=-1;

void push();
void pop();
void display();
void search(int k);

void main()
{
    int ch,k;
    while(1)
    {
        printf("\nMain Menu");
        printf("\n1.PUSH (Insert) in the Stack");
        printf("\n2.POP (Delete) from the Stack");
        printf("\n3.Display the Stack contents");
        printf("\n4.Search for element in the Stack");
        printf("\n5.Exit (End the Execution)");
        printf("\nEnter Your Choice: ");
        scanf ("%d",&ch);
        switch(ch)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: scanf("%d",&k);
            search(k);
            break;
            case 5: exit(0);
            default: printf("\nInvalid choice!!");
        }
    }
}

/*PUSH Function*/
void push()
{
    int x;
    if(top==SIZE-1)
        printf("Stack is full");
    else
    {
        printf ("Enter the Element to be pushed: ");
        scanf ("%d",&x);
        top=top+1;
        stack[top]=x;
    }
}

/*POP Function*/
void pop()
{
    if(top==-1)
        printf("Stack is empty");
    else
    {
        printf("%d is popped from stack",stack[top]);
        top=top-1;
    }
}

/*Function to DISPLAY Stack*/
void display()
{
    int i;
    if(top==-1)
        printf("Empty");
    else
    {
        printf("The elements in the stack are: ");
        for(i=top; i>=0; --i)
        {
            printf("\n--------\n|%3d |\n ------- ",stack[i]);
        }
    }
}

/*SEARCH Function*/
void search(k)
{
    int i,flag=0;
    for(i=top; i>=0; i--)
    {
        if(k==stack[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Search is successful");
    else
        printf("Search is unsuccessful");
}