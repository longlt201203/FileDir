#include "FileHandler.h"
#include "FileDirHandler.h"
#include <stdio.h>
#include <string.h>

int is_file_exist(char *path) {
	FILE *f = fopen(path,"r");
	if (f != NULL) {
		fclose(f);
		return 1;
	}
	return 0;
}

void file_make(char *path) {
	char command[MAX_COMMAND_LENGTH];
	strcpy(command,"type nul > \"");
	strcat(command,path);
	strcat(command,"\"");
	system(command);
}

void file_delete(char *path) {
	char command[MAX_COMMAND_LENGTH];
	strcpy(command,"del \"");
	strcat(command,path);
	strcat(command,"\" > NUL");
	system(command);
}

void file_copy(char *src_path, char *des_path) {
	char command[MAX_COMMAND_LENGTH];
	strcpy(command,"copy \"");
	strcat(command,src_path);
	strcat(command,"\" \"");
	strcat(command,des_path);
	strcat(command,"\" > NUL");
	system(command);
}
