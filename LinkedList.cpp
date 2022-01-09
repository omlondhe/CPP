#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
    int value;
    struct Node* next;
};

void linkedListTraversal(struct Node* head) {
    struct Node* tempHead = head;
    while (tempHead != NULL) {
        cout << tempHead->value << " -*> ";
        tempHead = tempHead->next;
    }
    cout << "NULL\n";
}

struct Node* insertInBeginning(struct Node* head, int value) {
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->value = value;
    newHead->next = head;
    return newHead;
}

void insertAtIndex(struct Node* head, int value, int index) {
    struct Node* tempHead = head;
    int i = 1;
    while (tempHead != NULL) {
        if(i == index) {
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->value = value;
            node->next = tempHead->next;
            tempHead->next = node;
            return;
        }
        tempHead = tempHead->next;
        i++;
    }
    cout << "Enter a valid index\n";
}

void insertAtLast(struct Node* head, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    
    struct Node* tempHead = head;
    while (tempHead->next != NULL) {
        tempHead = tempHead->next;
    }

    tempHead->next = node;
}

void insertAfter(struct Node* node, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = node->next;
    node->next = newNode;
}

struct Node* deleteFirstNode(struct Node* head) {
    struct Node* newHead = head->next;
    free(head);
    return newHead;
}

void deleteAtIndex(struct Node* head, int index) {
    struct Node* tempHead = head;
    struct Node* nextHead = head->next;
    
    for (int i = 0; i < index - 1; i++) {
        tempHead = tempHead->next;
        nextHead = nextHead->next;
    }
    tempHead->next = nextHead->next;
    free(nextHead);
}

void deleteWithValue(struct Node* head, int value) {
    struct Node* tempHead = head;
    struct Node* nextHead = head->next;
    
    while (nextHead->value != value && nextHead->next != NULL) {
        tempHead = tempHead->next;
        nextHead = nextHead->next;
    }
    if (nextHead->value == value) {
        tempHead->next = nextHead->next;
        free(nextHead);
    }
}

void deleteLastNode(struct Node* head) {
    struct Node* tempHead = head;
    while(tempHead->next->next != NULL) {
        tempHead = tempHead->next;
    }
    free(tempHead->next);
    tempHead->next = NULL;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->value = 7;
    head->next = second;
    
    second->value = 11;
    second->next = third;
    
    third->value = 21;
    third->next = NULL;

    linkedListTraversal(head);

    head = insertInBeginning(head, 24);
    linkedListTraversal(head);

    insertAtIndex(head, 30, 2);
    linkedListTraversal(head);
    insertAtIndex(head, 34, 7);
    insertAtIndex(head, 34, 4);
    linkedListTraversal(head);

    insertAtLast(head, 40);
    linkedListTraversal(head);

    insertAfter(third, 44);
    linkedListTraversal(head);

    head = deleteFirstNode(head);
    linkedListTraversal(head);

    deleteLastNode(head);
    linkedListTraversal(head);
    
    deleteAtIndex(head, 3);
    linkedListTraversal(head);
    
    deleteWithValue(head, 30);
    linkedListTraversal(head);

    return 0;
}
