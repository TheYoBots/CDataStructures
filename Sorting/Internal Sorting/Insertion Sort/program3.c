// Insertion Sort - Ascending order
// using functions

#include<stdio.h>

void InsertionSort(int a[], int n);

int main()
{
    int a[100],n,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    InsertionSort(a, n);
    for(i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}

void InsertionSort(int a[], int n)
{
    int i,j,index;
    for(i=1; i<n; i++)
    {
        index=a[i];
        j=i;
        while((j>0)&&(a[j-1]>index))
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=index;
    }
}