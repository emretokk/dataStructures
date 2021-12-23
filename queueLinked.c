#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int key;
	struct queue* next;
}queue;

int count;
queue* front = NULL;
queue* rear = NULL;

void enqueue(int data){
	queue* new = (queue*) malloc(sizeof(queue));
	//      liste boş
	if (front == NULL)
	{
		new->key = data;
		new->next = NULL;
		count += 1;
		front = new;
		rear = new;
	}
	//      overflow
	else if (count >= 10){
		printf(" Overflow !!");
	}
	//      listede eleman var
	else
	{
		new->key = data;
		new->next = NULL;
		count+=1;
		rear->next = new;
		rear = new;
	}
}

int dequeue(){
	//    liste boş
	if (front == NULL){
		return 0;
	}
	//    1 eleman var
	else if (rear == front)
	{
		int val = front->key;
		front = NULL;
		rear = NULL;
		free(front);
		count -= 1;
		return val;
	}
	//    1 den fazla eleman var
	else {
		int val = front->key;
		queue* nextt= front->next;
		free(front);
		front = nextt;
		count -= 1;
		return val;
	}

}

int main(int argc, char const *argv[])
{
	// queue* head = createQueue();

	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);


	int popped;
	popped = dequeue();
	popped = dequeue();
	popped = dequeue();

	queue* gez = front;
	while (gez != NULL){
		printf("%d", gez->key);
		gez = gez->next;
	}
	return 0;
}