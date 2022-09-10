// C program on realloc()

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int *)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        printf("Memory allocation allocated using calloc");
        for(i=0; i<n; i++)
            ptr[i]=i+1;
        printf("\nElements of array are:\n");
        for(i=0; i<n; i++)
            printf("%d\t",ptr[i]);
    }
    printf("\nEnter new Array Size: ");
    scanf("%d",&n);
    ptr=realloc(ptr,n*sizeof(int));
    printf("Memory successfully re-allocated using realloc");
    for(i=0; i<n; i++)
        ptr[i]=i+1;
    printf("\nElements of array are:\n");
    for(i=0; i<n; i++)
        printf("%d\t",ptr[i]);
    free(ptr);
    return 0;
}