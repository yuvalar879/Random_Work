/*
 ============================================================================
 Name        : Cwork.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cwork.h"

int main(void) {
	reverse("Hello");

	return 0;
}

char* reverse(char* a) {
	char* result = malloc(sizeof(a));

	for (int i = strlen(a); i >= 0; i--) {
		printf("%c", (char) a[i]);
	}

	return 0;
}
