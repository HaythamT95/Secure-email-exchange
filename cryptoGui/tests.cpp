/*

	FILENAME:  tests.c

	AES Submission: FROG

	Principal Submitter: TecApro

*/

#include <stdlib.h>
#include <string.h>

#include "frog.h"
#include "tests.h"

void outputBinary(char* Item, BYTE* value, int Size) {
	char outputBuffer[65];
	binaryToHexString(value, outputBuffer, Size);
	//fprintf(output, "%s=%s\n", Item, outputBuffer);
	printf("\n%s=%s\n", Item, outputBuffer);
}

