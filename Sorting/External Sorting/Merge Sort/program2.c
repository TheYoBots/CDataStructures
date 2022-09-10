// Program to implement merge sort - descending

#include<stdio.h>

void MergeSort(int a[], int low, int high);
void Merge(int a[], int low, int mid, int high);

int main()
{
    int a[100],n,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    MergeSort(a, 0, n-1);
    for(i=n-1; i>=0; i--)
    {
        printf("%4d",a[i]);
    }
    return 0;
}

void MergeSort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}

void Merge(int a[], int low, int mid, int high)
{
    int b[10],h,i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    for(i=low; i<=high; i++)
        a[i]=b[i];
}