// C program to implement Circular Queue operations.

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 3

int queue[QUEUE_SIZE];
int front=-1,rear=-1;

void enqueue(int);
void dequeue();
void display();

int main()
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
            default: printf("Invalid Choice!");
        }
    }
    return 0;
}

void enqueue(int ele)
{
    if(((rear==QUEUE_SIZE-1) && (front==-1)) || ((front==rear) && (front!=-1)))
        printf("\nQueue overflow!!");
    else if((rear==QUEUE_SIZE-1) && (front!=-1))
    {
        rear=0;
        queue[rear]=ele;
    }
    else
    {
        rear=rear+1;
        queue[rear]=ele;
    }
}

void dequeue()
{
    if((front==rear) && (front==-1))
        printf("Queue underflow!!");
    else
    {
        if(front==QUEUE_SIZE-1)
            front=-1;
            front=front+1;
            printf("Deleted element is:%d",queue[front]);
            if(front==rear)
                front=rear=-1;
    }
}

void display()
{
    int i;
    if((front==rear) && (front==-1))
        printf("Queue is empty");
    else
    {
        if(front<rear)
        {
            for(i=front+1; i<=rear; i++)
                printf("%5d", queue[i]);
        }
        else
        {
            for(i=0; i<=rear; i++)
                printf("%5d",queue[i]);
            for(i=front+1; i<=QUEUE_SIZE-1; i++)
                printf("%5d",queue[i]);
        }
    }
}