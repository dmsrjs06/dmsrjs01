#include <stdio.h>
#include <stdlib.h>
#include "arraylist10.h"

int main() {
    arrayList* myArrayList = createArrayList(10);
    int choice, pos, value;

    while (1) {
        printf("1. Insert\n");
        printf("2. delete\n");
        printf("3. replace\n");
        printf("4. print\n");
        printf("5. clear\n");
        printf("choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 값과 위치 입력: ");
            scanf_s("%d %d", &value, &pos);
            if (insertArrayList(myArrayList, pos, value))
                printf("입력 성공\n");
            else
                printf("재입력\n");
            break;
        case 2:
            printf("삭제할 위치 입력: ");
            scanf_s("%d", &pos);
            value = deleteArrayList(myArrayList, pos);
            if (value != 0)
                printf("삭제된 값: %d\n", value);
            else
                printf("삭제 실패\n");
            break;
        case 3:
            printf("교체할 값과 위치 입력: ");
            scanf_s("%d %d", &value, &pos);
            if (replaceItemArrayList(myArrayList, pos, value))
                printf("교체 성공\n");
            else
                printf("교체 실패\n");
            break;
        case 4:
            printArrayList(myArrayList);
            break;
        case 5:
            initArrayList(myArrayList);
            printf("리스트 초기화 성공\n");
            break;
        case 6:
            destroyArrayList(myArrayList);
            printf("종료\n");
            return 0;
        default:
            printf("1~6까지만 입력해주세요\n");
        }
    }
}
