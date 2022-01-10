#include<iostream>
#include<stdlib.h>

using namespace std;

struct CircularQueue {
    int size;
    int front;
    int rear;
    int* arr;
};

bool isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % queue->size) == queue->front;
}
bool isEmpty(struct CircularQueue* queue) {
    return queue->rear == queue->front;
}

void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        cout << "Queue full!\n";
        return;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = value;
}
void dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue empty!\n";
        return;
    }
    queue->front = (queue->front + 1) % queue->size ;
}

void showQueue(struct CircularQueue* queue) {
    cout << "<- ";
    for (int i = queue->front + 1; i != queue->rear; i = (i + 1) % queue->size) {
        cout << queue->arr[i] << " ";
    }
    cout << queue->arr[queue->rear] << " ";
    cout << "<-\n";    
}

int main() {
    struct CircularQueue queue;
    queue.front = 0;
    queue.rear = 0;
    queue.size = 4;
    queue.arr = (int*)malloc(queue.size * sizeof(int));

    showQueue(&queue);
    enqueue(&queue, 0);
    showQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    showQueue(&queue);
    enqueue(&queue, 3);
    showQueue(&queue);
    dequeue(&queue);
    showQueue(&queue);
    enqueue(&queue, 3);
    showQueue(&queue);

    return 0;
}
