// C program to implement queue operations using arrays.

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
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. End");
        printf("\nEnter your choice: ");
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
        printf("\nQueue is full");
    else
    {
        rear=rear+1;
        queue[rear]=ele;
    }
}

void dequeue()
{
    if(front==rear)
        printf("\nQueue is empty");
    else
    {
        front=front+1;
        printf("%d is deleted from Queue.\n",queue[front]);
        if(front==rear)
            front=rear=-1;
    }
}

void display()
{
    int i;
    if(front==rear)
        printf("Queue is empty");
    else
    {
        for(i=front+1; i<=rear; i++)
        {
            printf("%4d",queue[i]);
        }
    }
}