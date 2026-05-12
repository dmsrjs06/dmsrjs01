#include "LinkedList.h"

int main() {
	struct linkedList* myList1;
	myList1 = createLinkedList();

	printf("is myList1 empty: %s\n",
		(isEmptyLinkedList(myList1) == 1) ? "Yes" : "No");
	printf("size of myList1: %d\n", sizeLinkedList(myList1));

	insertFirstLinkedList(myList1, (PointType) { 10, 20, 0 });
	insertLastLinkedList(myList1, (PointType) { 20, 30, 0 });
	insertLastLinkedList(myList1, (PointType) { 30, 40, 0 });
	printLinkedList(myList1);

	insertItemLinkedList(myList1, myList1->head->next, (PointType) { 40, 50, 0 });
	insertItemLinkedList(myList1, NULL, (PointType) { 50, 60, 0 });
	printLinkedList(myList1);

	deleteFirstLinkedList(myList1);
	deleteFirstLinkedList(myList1);
	printLinkedList(myList1);

	deleteLastLinkedList(myList1);
	printLinkedList(myList1);
	deleteLastLinkedList(myList1);
	printLinkedList(myList1);
	deleteLastLinkedList(myList1);
	printLinkedList(myList1);
	deleteLastLinkedList(myList1);
	printLinkedList(myList1);

	deleteAtLinkedList(myList1, 1);
	printLinkedList(myList1);

	deleteAtLinkedList(myList1, 1);
	printLinkedList(myList1);

	deleteAtLinkedList(myList1, 0);
	printLinkedList(myList1);

	destroyLinkedList(myList1);
}