#include <stdio.h>

int nonzero(int n, int arr[10][10]) {
    int nonzero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                nonzero += 1;
            } 
        } 
    }
    if (nonzero == 0)
    {
        printf("No non-zero elements found in the given array!");
    }
    else printf("NO. of Non-Zero elements found : %d\n",nonzero);   
}

int upper(int n, int arr[10][10]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i>j)
            {
                printf(" \t");
            }
            else 
            {
                printf("%d",arr[i][j]);
                printf("\t");
            }
            
        }
        printf("\n");
    }
    printf("\n");
}

int ele_disp(int n, int arr[10][10]) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("X\t");
            }
            else
            {
                printf("%d",arr[i][j]);
                printf("\t");
            }
        }
        printf("\n");
    }
    
}

int main() {
    int n,arr[10][10];
    
    printf("Enter the size of square matrix : ");
    scanf("%d",&n);

    printf("Enter the elements of the matrix : ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }  
    }

    nonzero(n,arr);
    printf("Upper triangular matrix : \n");
    upper(n,arr);
    printf("Elements above and below diagoanl elements : \n");
    ele_disp(n,arr);
}