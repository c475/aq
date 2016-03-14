#include <stdio.h>
#include <stdlib.h>
#include "error.h"


void die(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}