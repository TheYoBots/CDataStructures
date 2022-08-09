/* Write a C program to implement Double Linked List

Test casses

case = t1
input=
1
12 1
1 
45 2
1 
34 1
3
5
output=
FORWARD Traversal: 34 12 45 
BACKWARD Traversal: 45 12 34                                                                               

case = t2
input= 
1
12 1
1 
45 2
1 
34 1
3
2
2
3
5
output =
FORWARD Traversal: 34 12 45 
BACKWARD Traversal: 45 12 34 
FORWARD Traversal: 34 45 
BACKWARD Traversal: 45 34 

case = t3
input= 
1                                                                               
12 1                                                                            
1                                                                               
13 3
5
output =
Enter a valid position 

case = t4
input=
1
10 1
1
20 2
1
45 2
3
2
3
3
5
output=
FORWARD Traversal: 10 45 20 
BACKWARD Traversal: 20 45 10 
FORWARD Traversal: 10 45 
BACKWARD Traversal: 45 10 

case = t5
input = 
1                                                                               
12 1                                                                            
1                                                                               
13 2                                                                            
4 40
5
output=
element not found   

case = t6
input = 
1                                                                               
12 1                                                                            
1                                                                               
13 2                                                                            
2 3 
5
output=                                                                                
Enter a valid position                                                          

case = t7
input =
3 
5
output =
DLL is empty
   
case =t9
input =
1
12 1
1
45 2
1
34 2
3
2
1
3
5
output=
FORWARD Traversal: 12 34 45 
BACKWARD Traversal: 45 34 12 
FORWARD Traversal: 34 45 
BACKWARD Traversal: 45 34 

case = t10
input = 
1                                                                               
12 1                                                                            
1                                                                               
13 2                                                                            
4 13
5
output=
13 found at position 2

case=t11
input=
1                                                                               
12                                                                              
1                                                                               
1                                                                               
23                                                                              
2                                                                               
1                                                                               
34                                                                              
3                                                                               
1                                                                               
56                                                                              
1                                                                               
4                                                                               
23  
5
output=
23 found at position 3

case = t12
input =
4 3 
5
output=
DLL is empty

case = t13
input =
1
12 1
1 
13 2
1
23 3
4 13
5
output=
13 found at position 2

*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
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
    scanf("%d%d",&n,&p);
    if(p<=0||p>c+1)
        printf("Enter a valid position");
    else
    {
        c++;
        temp->data=n;
        temp->next=NULL;
        temp->pre=NULL;
        if(head==NULL)
            head=temp;
        else if(p==1)
        {
            x=head;
            x->pre=temp;
            temp->next=x;
            head=temp;
        }
        else
        {
            temp2=head;
            for(i=1;i<p-1;i++)
            {
                temp2=temp2->next;
            }
            temp->next=temp2->next;
            temp2->next=temp;
            temp->pre=temp2;
            if(p!=c)
            {
                temp2=temp->next;
                temp2->pre=temp;
            }
        }
    }
}

void delete()
{
    int p,i;
    struct node *temp1=head,*temp2;
    scanf("%d",&p);
    if(p<=0||p>c)
        printf("Enter a valid position");
    else
    {
        c--;
        if(p==1)
        {
            head=temp1->next;
            if(c!=0)
            {
                temp2=temp1->next;
                temp2->pre=temp1->pre;
            }
            free(temp1);
        }
        else
        {
            for(i=1;i<p-1;i++)
            {
                temp1=temp1->next;
            }
            temp2=temp1->next;
            temp1->next=temp2->next;
            if(p!=c+1)
            {
                temp1=temp2->next;
                temp1->pre=temp2->pre;
            }
            free(temp2);
        }
    }
}

void search()
{
    int n,p=0;
    struct node *x;
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("DLL is empty");
        return;
    }
    x=head;
    while(x!=NULL)
    {
        p++;
        if(x->data==n)
        {
            b=1;
            break;
        }
        x=x->next;
    }
    if(b==1)
        printf("%d found at position %d",x->data,p);
    else
        printf("element not found");
}

void display()
{
    int i;
    struct node *x,*y;
    if(head==NULL)
    {
        printf("DLL is empty");
        return;
    }
    x=head;
    y=head;
    printf("\nFORWARD Traversal: ");
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }
    printf("\nBACKWARD Traversal: ");
    for(i=0;i<c-1;i++)
    {
        y=y->next;
    }
    while(y!=NULL)
    {
        printf("%d ",y->data);
        y=y->pre;
    }
}