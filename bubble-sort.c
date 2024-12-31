#include <stdio.h>
int main()
{
    int arr[5] = {9,1,3,11,8};
    int n = 5;
    int temp,flag;
    for (int i = 0; i < n-1; i++)
    {
        flag = 0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[i] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            
        }
        if (flag == 0)
        {
            break;
        }  
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

