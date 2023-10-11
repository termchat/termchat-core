#include <stdio.h>
#include "core.h"

int main(void) {
    char Buffer[100];

    GPTGetResponse("Say Hello!", "KEY", Buffer);

    return 0;
}