#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

// 행렬 원소 구조체
typedef struct {
    int row;
    int col;
    int value;
} elementArrayList;

// 순차리스트 구조체
typedef struct {
    elementArrayList* data;
    int size;
    int capacity;
} arrayList;

// 순차리스트 함수
arrayList* createArrayList(int size);
void destroyArrayList(arrayList* al);
int sizeArrayList(arrayList* al);
int insertArrayList(arrayList* al, int pos, elementArrayList item);
elementArrayList getItemArrayList(arrayList* al, int pos);

// 희소행렬 구조체 (이중 포인터 활용)
typedef struct {
    int rows;
    int cols;
    arrayList** matrix; // 각 행을 가리키는 포인터 배열
} sparseMatrix;

// 희소행렬 함수
sparseMatrix* createSparseMatrix(int rows, int cols);
void destroySparseMatrix(sparseMatrix* sm);
void initSparseMatrix(sparseMatrix* sm, int nonZeroCount);
void printSparseMatrixTable(sparseMatrix* sm);
sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount);

#endif
