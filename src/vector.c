#include "vector.h"
#include <stdlib.h>

Vector* vectorCreate(unsigned int capacity) {
    Vector* vector = malloc(sizeof(Vector));
    vector->count = 0;
    vector->capacity = 4;
    vector->content = calloc(vector->capacity, sizeof(int)*vector->capacity);
    return vector;
}

void vectorFree(Vector* vector) {
    free(vector->content);
    free(vector);
}

void vectorAdd(Vector* vector, int value) {
    if (vector->count < vector->capacity) {
        vector->content[vector->count++] = value;
    }
    else {
        vector->capacity *= 2;
        vector->content = realloc(vector->content, sizeof(int)*vector->capacity);
        vector->content[vector->count++] = value;
    }
}

void vectorRemove(Vector* vector, unsigned int index) {
    for (int i = index; i < vector->count; ++i) {
        vector->content[i] = vector->content[i+1];
    }
    --vector->count;
}