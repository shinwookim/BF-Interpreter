#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "interpreter.h"

int main(int argc, char **argv)
{
    FILE *file;

    /* Check Valid Usage */
    if (argc != 2)
    {
        puts("Usage: ./bf <SOURCE CODE>.bf");
        return -1;
    }

    /* Load Code from file */
    file = fopen(argv[1], "r");
    /* Get File Size */
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *code = (char *)malloc(file_size + 1);
    if (!code)
    {
        perror("Unable to allocate memory to load brainfuck instructions");
        exit(-2);
    }
    fread(code, file_size, sizeof(char), file);

    /* Statically Parse Code to Determine If We need to get user input */

    char *input = "";

    /* Run Interpreter */
    brainfuck(code, input);

    /* Clean Up */
    free(code);
    fclose(file);

    /* Terminate */
    return 0;
}
