// C program to implement Circular Linked List

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
    int a,ch;
    head=NULL;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit");
        printf("\nEnter your choice: ");
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
            default: printf("invalid choice");
        }
    }
}

void insert()
{
    int n,p,i;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node *temp2,*x;
    printf("Enter an element and its position: ");
    scanf("%d%d",&n,&p);
    if(p<=0||p>c+1)
        printf("Enter a valid position");
    else
    {
        c++;
        temp->data=n;
        temp->next=NULL;
        if(p==1)
        {
            temp->next=head;
            head=temp;
            x=head;
            for(i=1;i<c;i++)
                x=x->next;
            x->next=temp;
        }
        else
        {
            temp2=head;
            for(i=0;i<p-2;i++)
            {
                temp2=temp2->next;
            }
            temp->next=temp2->next;
            temp2->next=temp;
        }
    }
}

void delete()
{
    int p,i;
    struct node *temp1=head,*temp2,*x;
    printf("Enter position from which data must be deleted: ");
    scanf("%d",&p);
    if(p<=0||p>c)
        printf("Enter a valid position");
    else
    {
        c--;
        if(p==1)
        {
            head=temp1->next;
            free(temp1);
            x=head;
            for(i=1;i<c;i++)
            {
                x=x->next;
            }
            x->next=head;
        }
        else
        {
            for(i=0;i<p-2;i++)
            {
                temp1=temp1->next;
            }
            temp2=temp1->next;
            temp1->next=temp2->next;
            free(temp2);
        }
    }
}

void search()
{
    int n,p=0;
    struct node *x;
    printf("Enter element to be searched: ");
    scanf("%d",&n);
    x=head;
    do 
    {
        if(x==NULL)
        {
            printf("list is empty");
            return;
        }
        p++;
        if(x->data==n)
        {
            printf("%d found at position %d\n",x->data,p);
            return;
        }
        x=x->next;
    } while(x!=head);
    printf("element not found");
}

void display()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("list is empty");
        return;
    }
    do
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    } while(ptr!=head);
}