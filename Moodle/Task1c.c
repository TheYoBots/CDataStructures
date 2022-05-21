/* Write a C program to implement Insertion sort

Test Cases:
input = 5
2 5 6 10 3
output = 2 3 5 6 10
*/
//Start writing program from here

#include<stdio.h>

int main()
{
    int a[100],n,i,j,index;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        index=a[i];
        j=i;
        while((j>0) && (a[j-1]>index))
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