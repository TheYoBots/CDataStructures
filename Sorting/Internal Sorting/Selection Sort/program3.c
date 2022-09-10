// Selection sort - Ascending order
// using functions

#include<stdio.h>

void SelectionSort(int a[], int n);

int main()
{
    int a[100],n,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    SelectionSort(a, n);
    for(i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}

void SelectionSort(int a[], int n)
{
    int i,j,temp,min;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
}