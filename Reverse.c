/*
 ============================================================================
 Name        : Reverse.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : String Reverse in C11
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Reverse.h"

int main(void) {
	char* ToReverse = malloc(255);
	
	puts("Enter Text: ");

	gets(ToReverse);

	reverse(ToReverse);
	
	printf("\nPress Any Key to Continue \n");
	getch();
	
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
