/*
 ============================================================================
 Name        : TextToFile.c
 Author      : Yuval
 Version     :
 Copyright   : 
 Description : Text to File Writer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE *fp = fopen("file.txt","w");

	if (fp == NULL) {
		puts("Error opening files");
		exit(1);
	}

	puts("Enter text to be written to file:");

	char* text = malloc(255);

	gets(text);
	fprintf(fp,"%s\n",text);
	
	free(text);

	fclose(fp);
	
	

	return 0;
}
