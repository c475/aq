#include <stdio.h>
#include <stdlib.h>
#include "error.h"


void AQ_system_error_die(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
