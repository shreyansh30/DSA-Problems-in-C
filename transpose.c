#include <stdio.h>

int main() {
    int row, col, num;

    printf("Enter the number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &row, &col, &num);

    int sparse[num + 1][3];

    printf("Enter the sparse matrix in 3-tuple format:\n");
    for (int i = 1; i <= num; i++) {
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }

    int column_count[col];
    for (int i = 0; i < col; i++) {
        column_count[i] = 0;
    }

    for (int i = 1; i <= num; i++) {
        column_count[sparse[i][1]]++;
    }

    int start_pos[col];
    start_pos[0] = 1;
    for (int i = 1; i < col; i++) {
        start_pos[i] = start_pos[i - 1] + column_count[i - 1];
    }

    int transpose[num + 1][3];
    transpose[0][0] = col;
    transpose[0][1] = row;
    transpose[0][2] = num;

    for (int i = 1; i <= num; i++) {
        int col_index = sparse[i][1];
        int position = start_pos[col_index]++;
        transpose[position][0] = sparse[i][1];
        transpose[position][1] = sparse[i][0];
        transpose[position][2] = sparse[i][2];
    }

    printf("\nTranspose of the sparse matrix:\n");
    for (int i = 0; i <= num; i++) {
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }
}