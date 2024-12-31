#include <stdio.h>

int main()
{
    int x,fp[10],sp[10],res[10];
    
    printf("Enter the degree of polynomial : ");
    scanf("%d",&x);

    printf("Enter polynomial-1 from lowest to highest degree : ");
    for (int i = 0; i <= x; i++)
    {
        scanf("%d",&fp[i]);
    }
    printf("Enter polynomial-2 from lowest to highest degree : ");
    for (int i = 0; i <= x; i++)
    {
        scanf("%d",&sp[i]);
    }

    for (int i = 0; i <= x; i++)
    {
        res[i] = fp[i] + sp[i];
    }
    
    printf("Resultant Polynomial : ");
    for (int i = x; i >= 0; i--)
    {
        printf("%dx^%d ",res[i],i);
        if (i > 0) {
                printf("+ ");
    }
    }   
}
