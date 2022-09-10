// Program to merge two sorted arrays into a third array. - ascending

#include<stdio.h>

void mergesort(int a[],int b[],int c[],int n1,int n2);

void main()
{
    int a[10],b[10],c[10],i,n1,n2;
    scanf("%d %d",&n1,&n2);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    mergesort(a,b,c,n1,n2);
    for(i=0;i<n1+n2;i++)
    {
        printf("%3d",c[i]);
    }
}

void mergesort(int a[],int b[],int c[],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<n1) c[k++]=a[i++];
    while(j<n2) c[k++]=b[j++];
}