/*
 ============================================================================
 Name        : Cwork.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : String Reverse in C11
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cwork.h"

int main(void) {
	char* ToReverse = malloc(sizeof(256));

	gets(ToReverse);

	reverse(ToReverse);

	free(ToReverse);

	return 0;
}

char* reverse(const char* a) {

	/* Can also be saved
	 char* result = malloc(sizeof(a));
	 */

	for (int i = strlen(a); i >= 0; i--) {
		printf("%c", (char) a[i]);
	}

	/*
	 free(result);
	 */

	return 0;
}
