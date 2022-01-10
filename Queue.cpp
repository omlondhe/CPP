#include<iostream>
#include<stdlib.h>

using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int* arr;
};

bool isFull(struct Queue* queue) {
    return queue->rear == queue->size - 1;
}
bool isEmpty(struct Queue* queue) {
    return queue->rear == queue->front;
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        cout << "Queue full!";
        return;
    }
    queue->arr[++queue->rear] = value;
}
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue empty!";
        return;
    }
    queue->front++;
}

void showQueue(struct Queue* queue) {
    cout << "<-- ";
    for (int i = queue->front + 1; i <= queue->rear; i++) {
        cout << queue->arr[i] << " ";
    }
    cout << "\n";    
}

int main() {
    struct Queue queue;
    queue.front = -1;
    queue.rear = -1;
    queue.size = 100;
    queue.arr = (int*)malloc(queue.size * sizeof(int));

    showQueue(&queue);
    enqueue(&queue, 0);
    showQueue(&queue);
    showQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    showQueue(&queue);
    dequeue(&queue);
    showQueue(&queue);

    return 0;
}
