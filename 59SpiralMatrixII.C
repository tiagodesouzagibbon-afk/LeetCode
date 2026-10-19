#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    int** Matrix = (int**)malloc(n * sizeof(int*));
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        Matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    int count = 0, x = 0, y = 0, i = 1;

    while (i < ((n*n)+1)){
        //Completa primeira linha
        for (y; y < (n - count); y++){
            Matrix[x][y] = i++;
        }
        if (i > (n*n)) break;
        x++;
        y--;
        //Completa ultima coluna
        for (x; x < (n - count); x++){
            Matrix[x][y] = i++;
        }
        if (i > (n*n)) break;
        y--;
        x--;
        //Completa ultima linha
        for (y; y > (-1 + count); y--){
            Matrix[x][y] = i++;
        }
        if (i > (n*n)) break;
        count++;
        x--;
        y++;
        //Completa primeira coluna
        for (x; x > (-1 + count); x--){
            Matrix[x][y] = i++;
        }
        if (i > (n*n)) break;
        x++;
        y++;
    }
    
    return Matrix;
}


int main(){

    int n = 3, returnSize;
    int* returnColumnSizes;
    
    int** Matrix = generateMatrix(n, &returnSize, &returnColumnSizes);

    printf("Matrix Gerado: [%d x %d]:", returnSize, returnSize);

    for (int i = 0; i < n; i++){
        printf("\n[");
        for (int y = 0; y < n; y++){
            printf("%d", Matrix[i][y]);
            if (y != (n-1)) printf(",");
        }
        printf("]");
    }

    return 0;
}