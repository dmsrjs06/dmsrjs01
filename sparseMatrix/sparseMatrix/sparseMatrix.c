#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sparseMatrix.h"

//array list
arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
    al->size = 0;
    al->capacity = size;
    return al;
}

void destroyArrayList(arrayList* al) {
    free(al->data);
    free(al);
}

int sizeArrayList(arrayList* al) { return al->size; }

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size) return 0;
    if (al->size == al->capacity) {
        al->capacity *= 2;
        elementArrayList* newData = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * al->capacity);
        if (newData == NULL) return 0;
        al->data = newData;
    }
    for (int i = al->size; i > pos; i--) {
        al->data[i] = al->data[i - 1];
    }
    al->data[pos] = item;
    al->size++;
    return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    elementArrayList dummy = { 0,0,0 };
    if (pos < 0 || pos >= al->size) return dummy;
    return al->data[pos];
}

//sparse matrix
sparseMatrix* createSparseMatrix(int rows, int cols) {
    sparseMatrix* sm = (sparseMatrix*)malloc(sizeof(sparseMatrix));
    sm->rows = rows;
    sm->cols = cols;
    sm->matrix = (arrayList**)malloc(sizeof(arrayList*) * rows);

    for (int i = 0; i < rows; i++) {
        sm->matrix[i] = createArrayList(cols);
    }
    return sm;
}

void destroySparseMatrix(sparseMatrix* sm) {
    for (int i = 0; i < sm->rows; i++) {
        destroyArrayList(sm->matrix[i]);
    }
    free(sm->matrix);
    free(sm);
}

void initSparseMatrix(sparseMatrix* sm, int nonZeroCount) {
    srand((unsigned int)time(NULL));
    int count = 0;
    while (count < nonZeroCount) {
        int r = rand() % sm->rows;
        int c = rand() % sm->cols;
        int val = (rand() % 10) + 1;

        elementArrayList item = { r, c, val };
        insertArrayList(sm->matrix[r], sm->matrix[r]->size, item);
        count++;
    }
}

void printFullMatrix(sparseMatrix* sm) {
    printf("Full Matrix (%d x %d):\n", sm->rows, sm->cols);
    for (int i = 0; i < sm->rows; i++) {
        for (int j = 0; j < sm->cols; j++) {
            int found = 0;
            for (int k = 0; k < sizeArrayList(sm->matrix[i]); k++) {
                elementArrayList item = getItemArrayList(sm->matrix[i], k);
                if (item.col == j) {
                    printf("%3d ", item.value);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("%3d ", 0);
            }
        }
        printf("\n");
    }
    printf("\n");
}


sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount) {
    sparseMatrix* tsm = createSparseMatrix(sm->cols, sm->rows);
    *moveCount = 0;
    for (int i = 0; i < sm->rows; i++) {
        for (int j = 0; j < sizeArrayList(sm->matrix[i]); j++) {
            elementArrayList item = getItemArrayList(sm->matrix[i], j);
            elementArrayList transposed = { item.col, item.row, item.value };
            insertArrayList(tsm->matrix[item.col], tsm->matrix[item.col]->size, transposed);
            (*moveCount)++;
        }
    }
    return tsm;
}
