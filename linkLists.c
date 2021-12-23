#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
	int value;
	struct linkedList* next;
};

int main()
{
	struct linkedList *list1 = malloc(sizeof(struct linkedList));
	struct linkedList *list2 = malloc(sizeof(struct linkedList));
	struct linkedList *list3 = malloc(sizeof(struct linkedList));
	struct linkedList *list4 = malloc(sizeof(struct linkedList));
	struct linkedList *list5 = malloc(sizeof(struct linkedList));

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

	struct linledList *i = list1;
	while (i != NULL) {
		printf("%d", i->value);
		i = i->next;
	}

	
	return 0;
}