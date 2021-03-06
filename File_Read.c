/*
 ============================================================================
 Name        : File_Read.c
 Author      : Yuval
 Version     :
 Copyright   : 
 Description : Reads all the files in a given directory
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <windows.h>
#include "File_Read.h"

int main(void) {

	char* read = malloc(255);

	puts("Enter Directory: ");

	gets(read);

	int check = readfunc(read);

	if (check == OK)
		puts("\nSuccess");
	else
		puts("\nFailure");

	free(read);
	
	printf("\nPress Any Key to Continue \n");
	getch();

	return 0;
}

int readfunc(const char* directory) {
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(directory)) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			printf("%s\n", ent->d_name);
		}
		closedir(dir);
	} else {
		perror("");
		return EXIT_FAILURE;
	}

	return 0;
}
