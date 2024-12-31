#include <stdio.h>

int insert(int pos, int val, int n, int arr[10]) {

    if(pos < 0 || pos > n) {
        printf("Invalid position entry!");
    }
    else {
        n++;
        for(int i = n; i>pos ; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = val;
        printf("Value added to desired position.\n");
       
    }
}

int delete(int n, int arr[10], int dpos) {
    for (int i = dpos; i<n-1 ; i++) {
        arr[i] = arr[i+1];
    }
    printf("Desired data deleted!");
}

int search(int n, int arr[10], int svar) {
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (svar == arr[i])
        {
            flag = i;
            break;
        }       
        else flag = 0;
    }
    if (flag != 0)
    {
        printf("Requested data \"%d\" found at position : %d",arr[flag],flag+1);
    }
    else printf("No data found :(");
    
}

int traverse(int n, int arr[10]) {
    for (int i = 0; i<n; i++) {
        printf("%d ",arr[i]);
    }
}

int main() {
    int menu,n,pos,val,dpos,svar,i;
    int arr[10];
   
    printf("Enter the size of array : ");
    scanf("%d",&n);
   
    printf("Enter the elements of array : ");
    for(int i=0; i<n ; i++) {
        scanf("%d",&arr[i]);
    }
   
    printf("***Menu***\n");
    printf("1. Insert \n2. Delete\n3. Linear Search \n4. Traverse \n5. Exit\n");
   
    printf("Enter the option : ");
    scanf("%d",&menu);
   
    switch(menu) {
        case 1 :  
            printf("Enter the value : ");
            scanf("%d",&val);
            printf("Enter the position : ");
            scanf("%d",&pos);
            insert(pos,val,n,arr);
            n++;
            traverse(n,arr); 
            break;          
           
       case 2 :
            printf("Enter the position : ");
            scanf("%d",&dpos);
            delete(n,arr,dpos);
            n--;
            traverse(n,arr);
            break;

        case 3 :
            printf("Enter the value to search : ");
            scanf("%d",&svar);
            int res = search(n,arr,svar);            
            break;
           
       case 4 :
            printf("Array elements : ");
            traverse(n,arr);
            break;

        case 5 : 
            printf("Closing Program....");
            break;

    }
}