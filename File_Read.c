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
#include "File_Read.h"

int main(void) {

	int check = readfunc("D:\\test");

	if (check == OK)
		puts("\nSuccess");
	else
		puts("\nFailure");

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
