#include <stdio.h>

int nonzero(int r,int c,int mat[10][10]) {
    int nonzero = 0;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(mat[i][j] != 0){
                nonzero += 1;
            }
        }
    }
    return nonzero;
}

int main() {
    int r,c,mat[10][10],tup[10][10];
    
    printf("Enter the size of array : ");
    scanf("%d %d",&r,&c);
    
    printf("Enter the elements of sparse matrix : ");
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    int nonzero_ele;
    nonzero_ele = nonzero(r,c,mat);
    
    tup[0][0] = r;
    tup[0][1] = c;
    tup[0][2] = nonzero_ele;
    int s=1;
    
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            if(mat[i][j] != 0){
                tup[s][0] = i;
                tup[s][1] = j;
                tup[s][2] = mat[i][j];
                s++;       
            }
        }
    }
    
    for(int i = 0; i<=nonzero_ele; i++){
        for(int j=0; j<3; j++){
            printf("%d ",tup[i][j]);
        } printf("\n");
    }
}
