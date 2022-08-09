/*
Implementation of Preorder, Inorder and Postorder in a Binary search tree (BST) using recursion and develop insert function.
Note: ensure after entering zero as node value to stop inserting into BST.

Test Cases:

Case=t1
Input=
8
7
14
0
Output=
Inorder traversal:7->8->14->
Preorder traversal:8->7->14->
Postorder traversal:7->14->8->

Case=t2
Input=
50
40
60
0
Output=
Inorder traversal:40->50->60->
Preorder traversal:50->40->60->
Postorder traversal:40->60->50->

Example: 
Enter node value,zero to stop:50                                                
Enter node value,zero to stop:40                                                
Enter node value,zero to stop:60                                                
Enter node value,zero to stop:0                                                 

Inorder traversal:40->50->60->                                                  
Preorder traversal:50->40->60->                                                 
Postorder traversal:40->60->50->
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};


struct node *newNode(int n)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=temp->right=NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root!=NULL)
    {
        printf("%d->",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d->",root->data);
    }
}

struct node *insert(struct node *node, int data) 
{
    if(node==NULL)
        return newNode(data);
    if(data<node->data)
        node->left=insert(node->left, data);
    else
        node->right=insert(node->right, data);
    return node;
}

int main()
{
    int x;
    struct node *root=NULL;
    while(1)
    {
        printf("\nEnter node value,zero to stop:");
        scanf("%d",&x);
        if(x==0)
            break;
        root=insert(root,x);
    }
    printf("\nInorder traversal:");
    inorder(root);
    printf("\nPreorder traversal:");
    preorder(root);
    printf("\nPostorder traversal:");
    postorder(root);
    return 0;
}