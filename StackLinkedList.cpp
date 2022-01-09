#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
    int value;
    struct Node* next;
};

bool isFull() {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    bool full = node == NULL;
    free(node);
    return full;
}

bool isEmpty(struct Node* top) {
    if (top == NULL) return true;
    return false;
}

struct Node* push(struct Node* top, int value) {
    if (isFull()) {
        cout << "Stack overflow!";
        return NULL;
    }
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = top;
    top = node;
    return top;
}

struct Node* pop(struct Node* top) {
    if (isEmpty(top)) {
        cout << "Stack underflow\n";
        return NULL;
    }
    struct Node* node = top;
    top = top->next;
    free(node);
    return top;
 }

int peek(struct Node* top, int position) {
    if (position <= 0) return -1;
    struct Node* tempTop = top;
    for (int i = 0; i < position - 1 && tempTop != NULL; i++) {
        tempTop = tempTop->next;
    }
    if (tempTop == NULL) return -1;
    return tempTop->value;
}

int stackTop(struct Node* top) {
    if (isEmpty(top)) {
        cout << "Stack underflow\n";
        return -1;
    }
    return top->value;
}

int stackBottom(struct Node* top) {
    if (isEmpty(top)) {
        cout << "Stack underflow\n";
        return -1;
    }
    struct Node* tempTop = top;
    while (tempTop->next != NULL) {
        tempTop = tempTop->next;
    }
    return tempTop->value;
 }

void showValues(struct Node* top) {
    struct Node* tempTop = top;
    while (tempTop != NULL) {
        cout << tempTop->value << "-->";
        tempTop = tempTop->next;
    }
    cout << "\n";
}

int main() {
    struct Node* top = NULL;
    top = push(top, 0);
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    showValues(top);
    top = pop(top);
    showValues(top);
    cout << peek(top, 0) << "\n";
    cout << peek(top, 2) << "\n";
    cout << peek(top, 5) << "\n";
    cout << stackTop(top) << "\n";
    cout << stackBottom(top) << "\n";
    return 0;
}
