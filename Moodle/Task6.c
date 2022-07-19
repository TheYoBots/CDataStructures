/* Write a C program to implement Singly Linked List operations. 

Test Case examples:

input= 
1                                                                               
12 1                                                                            
1                                                                               
14 1                                                                            
1                                                                               
24 2                                                                            
3

output =
14-> 24-> 12->

input= 
1                                                                               
12 1                                                                            
1                                                                               
13 3
5
output =
Enter a valid position 

*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insert();
void delete();
void display();
void search();

int c=0,b=0;

void main()
{
    int ch;
    head=NULL;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: search();
                    break;
            case 5: exit(0);
            default: printf("Invalid option");
        }
    }
}

void insert()
{
    int p,i,n;
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    struct node *temp2;
    scanf("%d %d",&n,&p);
    if(p<=0 || p>c+1)
        printf("\nEnter a valid position");
    else
    {
        c++;
        temp->data=n;
        temp->next=NULL;
        if(p==1)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            temp2=head;
            for(i=0; i<p-2; i++)
                temp2=temp2->next;
            temp->next=temp2->next;
            temp2->next=temp;
        }
    }
}

void delete()
{
    int p,i;
    struct node *temp1=head,*temp2;
    scanf("%d",&p);
    if(p<=0 || p>c || c==0)
        printf("\nEnter a valid position\n");
    else
    {
        if(p==1)
            head=head->next;
        else
        {
            for(i=1; i<p; i++)
            {
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=temp1->next;
        }
        c--;
        free(temp1);
    }
}

void search()
{
    int n,p=0;
    struct node *x;
    scanf("%d",&n);
    x=head;
    if(x->data==n)
        printf("\n%d is found at position %d",n,p);
    else
        printf("\n%d element not found",n);
}

void display()
{
    struct node *x;
    x=head;
    while(x!=NULL)
    {
        printf("%d-> ",x->data);
        x=x->next;
    }
}