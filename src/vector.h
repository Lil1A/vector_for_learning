#pragma once

typedef struct Vector {
    int count;
    int capacity;
    int* content;
} Vector;

Vector* vectorCreate(unsigned int capacity);
void vectorFree(Vector* vector);
void vectorAdd(Vector* vector, int value);
void vectorRemove(Vector* vector, unsigned int index);
