#include <stdio.h>

int main() {
    int r1, c1, v1;
    int r2, c2, v2;
    int i, j, k;
    int row, col, value;
    int result[10][3]; 
    int resultCount = 0;     

    printf("Enter sparse matrix-1 in 3-tuple format\n");
    scanf("%d %d %d", &r1, &c1, &v1);
    
    int matrix1[10][3]; 
    for (i = 0; i < v1; i++) {
        scanf("%d %d %d", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
    }

    printf("Enter sparse matrix-2 in 3-tuple format\n");
    scanf("%d %d %d", &r2, &c2, &v2);
    
    int matrix2[10][3]; 
    for (i = 0; i < v2; i++) {
        scanf("%d %d %d", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
    }

    if (r1 != r2 || c1 != c2) {
        printf("Matrix dimensions do not match.\n");
        return 1;
    }

    for (i = 0; i < v1; i++) {
        result[resultCount][0] = matrix1[i][0];
        result[resultCount][1] = matrix1[i][1];
        result[resultCount][2] = matrix1[i][2];
        resultCount++;
    }

    for (i = 0; i < v2; i++) {
        int found = 0;
        for (j = 0; j < v1; j++) {
            if (matrix2[i][0] == matrix1[j][0] && matrix2[i][1] == matrix1[j][1]) {
                result[j][2] += matrix2[i][2];
                found = 1;
                break;
            }
        }
        if (!found) {
            result[resultCount][0] = matrix2[i][0];
            result[resultCount][1] = matrix2[i][1];
            result[resultCount][2] = matrix2[i][2];
            resultCount++;
        }
    }

    printf("Resultant Matrix in 3-tuple format\n");
    printf("%d %d %d\n", r1, c1, resultCount);
    for (i = 0; i < resultCount; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}
