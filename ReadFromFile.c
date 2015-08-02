/*
 ============================================================================
 Name        : ReadFromFile.c
 Author      : Yuval
 Version     :
 Copyright   : 
 Description : Reads text files
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int c;
	FILE *fp;
	fp = fopen("file.txt", "r");
	if (fp) {
		while ((c = getc(fp)) != -1) {
			putchar(c);
		}
		fclose(fp);
	}

	return 0;
}
