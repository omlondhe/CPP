#include<iostream>
#include<stdlib.h>

using namespace std;

struct Stack {
    int size;
    int top;
    int* arr;
};

inline bool isFull(struct Stack *stack) {
    return stack->top == stack->size - 1;
}

inline bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        cout << "Stack overflow\n";
        return;
    }
    stack->arr[++stack->top] = value;
}

void pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow\n";
    }
    stack->arr[stack->top--] = -1;
}

int peek(struct Stack* stack, int position) {
    if ((stack->top - position + 1) < 0) {
        cout << "Not a valid position!\n";
        return -1;
    }
    return stack->arr[stack->top - position + 1];
}

int main() {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = 10;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));

    push(stack, 9);
    push(stack, 8);
    push(stack, 7);
    push(stack, 6);
    push(stack, 4);
    push(stack, 3);
    push(stack, 5);
    push(stack, 2);
    push(stack, 1);
    push(stack, 0);

    cout << peek(stack, 1) << "\n";
    cout << peek(stack, 2) << "\n";
    cout << peek(stack, 3) << "\n";
    cout << peek(stack, 4) << "\n";
    cout << peek(stack, 5) << "\n";
    cout << peek(stack, 6) << "\n";
    cout << peek(stack, 7) << "\n";
    cout << peek(stack, 8) << "\n";
    cout << peek(stack, 9) << "\n";
    cout << peek(stack, 10) << "\n";

    
    return 0;
}

