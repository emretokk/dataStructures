#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *pre;
	int data;
	int priority;
	struct node *next;
}; 
struct node* head;

//         deger     oncelik
void push(int val, int p){
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->data = val;
	if (head == NULL){
		new->next = NULL;
		new->pre = NULL;
		new->priority = p;
		head = new;
	}
	else{
		struct node *gez = head;
		struct node *parent = NULL;
		// oncelige gore eklenilecek yeri bul
		while (gez != NULL && gez->priority <= p){
			parent = gez;
			gez = gez->next;
		}
		// Listede 1 eleman varsa ve yeni elemanin onceligi listedekinden kucukse
		// Basa ekle
		if (parent == NULL){
			new->next = head;
			head->pre = new;
			head = new;
		}
		// Listenin sonuna ekle
		else if (gez == NULL){
			parent->next = new;
			new->pre = parent;
		}
		// oncelige gore araya eklei
		// parent ile gez arasina ekliyor
		else{
			parent->next = new;
			new->pre = parent;
			new->next = gez;
			gez->pre = new;
		}
	}
}

int main()
{
	push(11,3);
	push(22,2);
	push(33,3);
	push(44,2);
	push(55,1);
	push(66,3);
	push(77,1);
	push(88,2);
	push(99,1);
	push(100,1);
	struct node* gez = head;
	while (gez != NULL){
		printf("%d\n", gez->data);
		gez = gez->next;
	}
	return 0;
}