#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} elementArrayList;

typedef struct {
    elementArrayList* data;
    int size;
    int capacity;
} arrayList;

arrayList* createArrayList(int size);
void destroyArrayList(arrayList* al);
int sizeArrayList(arrayList* al);
int insertArrayList(arrayList* al, int pos, elementArrayList item);
elementArrayList getItemArrayList(arrayList* al, int pos);

typedef struct {
    int rows;
    int cols;
    arrayList** matrix;
} sparseMatrix;

sparseMatrix* createSparseMatrix(int rows, int cols);
void destroySparseMatrix(sparseMatrix* sm);
void initSparseMatrix(sparseMatrix* sm, int nonZeroCount);
void printSparseMatrixTable(sparseMatrix* sm);
sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount);
