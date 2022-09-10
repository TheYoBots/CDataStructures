// C program on malloc()

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        printf("Memory allocation allocated using malloc");
        for(i=0; i<n; i++)
            ptr[i]=i+1;
        printf("\nElements of array are:\n");
        for(i=0; i<n; i++)
            printf("%d\t",ptr[i]);
    }
    return 0;
}