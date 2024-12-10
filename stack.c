#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "macros.h"

int buffer_overflow(char *str)
{
	char buffer[24];

	// When we copy from the str pointer, it is our file that contains the illegal shellcode
    // That eventually gets ran
	strcpy(buffer, str);
	return 1;
}

int main(int argc, char **argv)
{
	char str[BUFFER_SIZE];

	FILE *badfile;
	badfile = fopen("badfile", "r");

	fread(str, sizeof(char), BUFFER_SIZE, badfile);

	buffer_overflow(str);

    // Should not get here
	printf("Returned Properly (No issues)\n");
	return 1;
}