#include "DirHandler.h"
#include "FileDirHandler.h"
#include <dirent.h>
#include <string.h>

int is_dir_exist(char *path) {
	DIR *d = opendir(path);
	if (d != NULL) {
		closedir(d);
		return 1;
	}
	return 0;
}

void dir_make(char *path) {
	char command[MAX_COMMAND_LENGTH];
	strcpy(command,"md \"");
	strcat(command,path);
	strcat(command,"\" > NUL");
	system(command);
}

void dir_delete(char *path) {
	char command[MAX_COMMAND_LENGTH];
	strcpy(command,"rd /s/q \"");
	strcat(command,path);
	strcat(command,"\" > NUL");
	system(command);
}

void dir_copy(char *src_path, char *des_path) {
	char command[MAX_COMMAND_LENGTH];
	strcpy(command,"xcopy \"");
	strcat(command,src_path);
	strcat(command,"\" \"");
	strcat(command,des_path);
	strcat(command,"\" /E/H/I/Y > NUL");
	system(command);
}
