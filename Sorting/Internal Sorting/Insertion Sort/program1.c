// Insertion Sort - Ascending order

#include<stdio.h>

int main()
{
    int a[100],n,i,j,index;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
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
    for(i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}