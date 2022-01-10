#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
    int value;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        cout << "Queue is Full!";
        free(node);
        return;
    }
    
    node->value = value;
    node->next = NULL;
    
    if (front == NULL) {
        front = node;
        rear = node;
        return;
    }

    rear->next = node;
    rear = node;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty!\n";
        return;
    }

    struct Node* tempFront = front;
    front = front->next;
    free(tempFront);
}

void showQueue() {
    struct Node* tempFront = front;
    while (tempFront != NULL) {
        cout << tempFront->value << " ";
        tempFront = tempFront->next;
    }
    cout << "\n";
}

int main() {
    showQueue();
    enqueue(0);
    showQueue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    showQueue();
    dequeue();
    showQueue();

    return 0;
}
