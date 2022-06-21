/* Write a C program to implement QUEUE operations using array

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
output = 12 21 45

example 2:
case = t2
input = 2 4
output = queue is empty
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 3

int queue[QUEUE_SIZE];
int front=-1,rear=-1;

void enqueue(int);
void dequeue();
void display();

void main()
{
    int ch,ele;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: scanf("%d",&ele);
            enqueue(ele);
            break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!");
        }
    }
}

void enqueue(int ele)
{
    if(rear==QUEUE_SIZE-1)
        printf("\nqueue is full");
    else
    {
        rear=rear+1;
        queue[rear]=ele;
    }
}

void dequeue()
{
    if(front==rear)
        printf("queue is empty");
    else
    {
        front=front+1;
        printf("%d is deleted from queue\n",queue[front]);
        if(front==rear)
            front=rear=-1;
    }
}

void display()
{
    int i;
    if(front==rear)
        printf("queue is empty");
    else
    {
        for(i=front+1; i<=rear; i++)
        {
            printf("%4d",queue[i]);
        }
    }
}