#include <stdio.h>
#include "../tests/vectorTest.h"

int main(void) 
{
    vectorCreateTest();

    vectorAddTest();

    vectorRemoveTest();

    vectorFreeTest();

    getchar();

    return 0;
}