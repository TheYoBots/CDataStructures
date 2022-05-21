/* Write a C program to implement Selection sort

Test Cases:
input = 5
2 5 6 10 3
output = 2 3 5 6 10
*/
//Start writing program from here

#include<stdio.h>

int main()
{
    int a[100],n,i,j,temp,min;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
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
    for(i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}