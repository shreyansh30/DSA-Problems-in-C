#include <stdio.h>
int main()
{
    int arr[5] = {9,1,3,11,8};
    int n = 5;
    int temp;

    for (int i = 0; i < n; i++)
    {
        temp = arr[i];
        int j= i-1;
        while (i>=n && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}