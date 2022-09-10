// C program on free()

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr,*ptr1;
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    ptr1=(int *)calloc(n,sizeof(int));
    if(ptr==NULL || ptr1==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        printf("\nMemory allocation allocated using malloc");
        free(ptr);
        printf("\nMalloc successfully freed\n");
        printf("\nMemory allocation allocated using calloc");
        free(ptr1);
        printf("\nCalloc successfully freed");
    }
    return 0;
}