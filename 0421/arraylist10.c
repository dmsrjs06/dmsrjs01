#include <stdio.h>
#include <stdlib.h>
#include "arraylist10.h"

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

int isEmptyArrayList(arrayList* al) { return (al->size == 0); }
int isFullArrayList(arrayList* al) { return (al->size == al->capacity); }
int sizeArrayList(arrayList* al) { return al->size; }

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (item <= 0) {
        printf("오류: 양의 정수만 입력 가능합니다.\n");
        return 0;
    }
    if (pos < 0 || pos > al->size) return 0;

    if (isFullArrayList(al)) {
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

elementArrayList deleteArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) return 0;
    elementArrayList item = al->data[pos];
    for (int i = pos; i < al->size - 1; i++) {
        al->data[i] = al->data[i + 1];
    }
    al->size--;
    return item;
}

int initArrayList(arrayList* al) {
    al->size = 0;
    return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    return al->data[pos];
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (item <= 0) {
        printf("오류: 양의 정수만 입력 가능합니다.\n");
        return 0;
    }
    if (pos < 0 || pos >= al->size) return 0;
    al->data[pos] = item;
    return 1;
}

void printArrayList(arrayList* al) {
    printf("순차 리스트: ");
    for (int i = 0; i < al->size; i++) {
        printf("[%d]=%d ", i, al->data[i]);
    }
    printf("\n");
}
