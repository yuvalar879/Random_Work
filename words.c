/*
 ============================================================================
 Name        : words.c
 Author      : Yuval
 Version     :
 Copyright   : 
 Description : Word Counter in C11
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void) {

	puts("Enter text, 255 char maximum: ");

	short words = 0;

	char* text = malloc(255);

	gets(text);

	for (char* i = text; *i; i++) {
		if (*i != ' ') {
			words++;
		}
	}

	printf("%d", words);

	free(text);
	
	printf("\nPress Any Key to Continue \n");
	getch();

	return 0;
}

