#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nfgets(char put_array[], int max_size);

void nfgets(char put_array[], int max_size)
{
    fgets(put_array, max_size, stdin);
    size_t length = strlen(put_array);
    if (put_array[length - 1] == '\n'){
        put_array[length - 1] = '\0';
    }
}
