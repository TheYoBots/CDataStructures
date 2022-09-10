// Sort numbers in descending order.
// Bubble Sort

#include<stdio.h>

int main()
{
    int a[100],n,i,j,temp;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    // Sort the list
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    // Print sorted list
    for(i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}