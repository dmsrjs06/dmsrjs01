#include <stdio.h>
#include "sparseMatrix.h"

int main() {
    sparseMatrix* sm = createSparseMatrix(10, 10);
    initSparseMatrix(sm, 20);

    printf("희소행렬:\n");
    printFullMatrix(sm);

    int moveCount = 0;
    sparseMatrix* tsm = transposeSparseMatrix(sm, &moveCount);

    printf("\n전치행렬:\n");
    printFullMatrix(tsm);

    printf("\n데이터 이동 횟수: %d\n", moveCount);

    destroySparseMatrix(sm);
    destroySparseMatrix(tsm);
    return 0;
}
