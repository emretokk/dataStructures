#include <iostream>
using namespace std;

struct linkedList
{
	int value;
	struct linkedList* next;
};

void printLinkedList(struct linkedList* list){
	while (list != NULL) {
		printf("%d", list->value);
		list = list->next;
	}
}

int main()
{
	struct linkedList *list1 = malloc(sizeof(struct linkedList));
	struct linkedList *list2 = NULL;
	struct linkedList *list3 = NULL;
	struct linkedList *list4 = NULL;
	struct linkedList *list5 = NULL;

	// list1 = (struct linkedList*)malloc(sizeof(struct linkedList));
	// list2 = (struct linkedList*)malloc(sizeof(struct linkedList));
	// list3 = (struct linkedList*)malloc(sizeof(struct linkedList));
	// list4 = (struct linkedList*)malloc(sizeof(struct linkedList));
	// list5 = (struct linkedList*)malloc(sizeof(struct linkedList));

	list1->value = 1;
	list2->value = 2;
	list3->value = 3;
	list4->value = 4;
	list5->value = 5;

	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list5;
	list5->next = NULL;

	printLinkedList(list1);


	
	return 0;
}