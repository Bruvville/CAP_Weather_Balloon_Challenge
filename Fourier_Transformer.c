#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Formulas.h"


int main() {

	FILE *dptr;
	dptr = fopen("Data.txt", "r");

	char dater[1000];

	while (fgets(dater, 1000, dptr)) {
		printf("%s", dater);
	}


	fclose(dptr);

	return 0;
}