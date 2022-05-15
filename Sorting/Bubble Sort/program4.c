// Sort numbers in ascending order using Functions.
// Bubble Sort

#include<stdio.h>

void BubbleSort(int a[], int n);

int main()
{
    int a[100],n,i,j,temp;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    BubbleSort(a, n);
    // Print sorted list
    for(i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}

void BubbleSort(int a[], int n)
{
    int i,j,temp;
    // Sort the list
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}