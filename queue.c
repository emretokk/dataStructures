#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int head, tail, size;
    int *arr;
}queue;

queue* createQueue(int capacity){
    queue* Q = (queue*) malloc(sizeof(queue));
    Q->head = 0;
    Q->tail = 0;
    Q->size = 0;
    Q->arr = (int*) malloc(sizeof(int) * capacity);
    return Q;
}

void enqueue(queue* Q, int val){
    Q->arr[Q->tail] = val;
    Q->size += 1;
    if (Q->tail == Q->size){
        Q->tail = 1;
    }
    else{
        Q->tail +=1;
    }
}

int dequeue(queue* Q){
    int x = Q->arr[Q->head];
    Q->arr[Q->head] = 0;

    if (Q->head == Q->size){
        Q->head = 0;
    }
    else{
        Q->head +=1;
    }
    return x;
}

int main(){
    queue* Q = createQueue(10);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);

    int popped;
    popped = dequeue(Q);

    for (int i=0; i<10; i++){
        printf("%d",Q->arr[i]);
    }

    printf("\nHead is: %d \nTail is: %d",Q->head, Q->tail);
    return 0;
}
