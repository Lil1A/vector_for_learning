#include "vectorTest.h"
#include <Windows.h>
#include "../src/vector.h"
#include <stdio.h>

#define true 1
#define false 0


void vectorCreateTest() {
    Vector* vector = vectorCreate(4);
    if (vector->content != NULL) 
    {
        Passed("Teszt 1 sikeres.", true);
    }
    else Passed("Teszt 1 sikertelen.", false);
}

void vectorAddTest() {
    Vector* vector = vectorCreate(4);
    vectorAdd(vector, 2);
    vectorAdd(vector, 5);
    vectorAdd(vector, 63);
    vectorAdd(vector, 420);
    vectorAdd(vector, 69);
    vectorAdd(vector, -8923);

    int goodValues[] = {2, 5, 63, 420, 69, -8923};

    for (int i = 0; i < vector->count; ++i) {
        if (vector->content[i] != goodValues[i]) {
            Passed("Teszt 2 sikertelen.", false);
            return;
        }
    }
    Passed("Teszt 2 sikeres.", true);
}

void vectorRemoveTest() {
    Vector* vector = vectorCreate(4);
    vectorAdd(vector, 2);
    vectorAdd(vector, 5);
    vectorAdd(vector, 63);
    vectorAdd(vector, 420);
    vectorAdd(vector, 69);
    vectorAdd(vector, -8923);

    vectorRemove(vector, 2);
    vectorRemove(vector, 2);

    int goodValues[] = {2, 5, 69, -8923};

    for (int i = 0; i < vector->count; ++i) {
        if (vector->content[i] != goodValues[i]) {
            Passed("Teszt 3 sikertelen.", false);
            return;
        }
    }
    Passed("Teszt 3 sikeres.", true);
}

void vectorFreeTest() {
    Vector* vector1 = vectorCreate(4);
    Vector* vector2 = vectorCreate(16);
    Vector* vector3 = vectorCreate(57);

    vectorFree(vector1);
    vectorFree(vector2);
    vectorFree(vector3);
    
    if (vector1->capacity == 4 && vector2->capacity == 16 && vector3->capacity == 57)
        Passed("Teszt 4 sikertelen.", false);
    else Passed("Teszt 4 sikeres.", true);
}

void Passed(const char* message, int isSuccess) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isSuccess) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    else SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);

    printf("%s\n", message);

    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}