#include<stdio.h>
#include<stdlib.h>

struct Array {
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct Array *arr, int tSize, int uSize) {
    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int*)malloc(tSize * sizeof(int));
}

void add(struct Array *arr) {
    for (int i = 0; i < arr->used_size; i++)
    {
        int n;
        printf("Enter element %d:\t", i);
        scanf("%d", &n);
        (arr->ptr)[i] = n;
    }
    
}

void show(struct Array *arr) {
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", (arr->ptr)[i]);
    }
    
}

int main() {
    struct Array marks;

    createArray(&marks, 100, 2);
    add(&marks);
    show(&marks);

    return 0;
}
