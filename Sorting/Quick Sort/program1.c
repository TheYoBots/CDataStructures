// Quick Sort - Ascending

#include<stdio.h>

void QuickSort(int a[], int left, int right);

void main( )
{
    int n,i,a[10];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    QuickSort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%4d",a[i]);
    }
}

void QuickSort(int a[], int left, int right)
{
    int pivot,t,i,j,l,r;
    if(left<right)
    {
        pivot=a[left];
        l=left;
        r=right;
        while(l<r)
        {
            while(a[l]<=pivot && l<=right)
                l++;
            while(a[r]>pivot)
                r--;
            if(l<r)
            {
                t=a[l];
                a[l]=a[r];
                a[r]=t;
            }
        }
        t=a[left];
        a[left]=a[r];
        a[r]=t;
        QuickSort(a, left, r-1);
        QuickSort(a, r+1, right);
    }
}