#include <stdio.h>
#include "FileHandler.h"
#include "DirHandler.h"

void display_menu();
int get_choice(char *display_msg, int min, int max);
void get_user_input(char *buffer, char *display_msg);
void new_folder();
void new_file();
void delete_folder();
void delete_file();

int main(int argc, char **argv) {
	int choice;
	do {
		display_menu();
		choice = get_choice("Input your choice",1,5);
		switch (choice) {
			case 1:
				new_folder();
				break;
			case 2:
				new_file();
				break;
			case 3:
				delete_folder();
				break;
			case 4:
				delete_file();
				break;
		}
	} while (choice != 5);
	return 0;
}

void display_menu() {
	system("cls");
	printf("Hello World!\nWhat you want me to do?\n");
	printf("1. New Folder\n");
	printf("2. New File\n");
	printf("3. Delete Folder\n");
	printf("4. Delete File\n");
	printf("5. Quit\n");
}

int get_choice(char *display_msg, int min, int max) {
	char c;
	int ok, rs;
	ok = 0;
	do {
		printf("%s: ",display_msg);
		scanf("%d",&rs);
		if (rs >= min && rs <= max) {
			ok = 1;
		}
		while (getchar() != '\n') {}
	} while (!ok);
	return rs;
}

void get_user_input(char *buffer, char *display_msg) {
	printf("%s: ",display_msg);
	gets(buffer);
}

void new_folder() {
	system("cls");
	char folder_path[255];
	get_user_input(folder_path,"Type your folder path here");
	if (is_dir_exist(folder_path)) {
		printf("Folder %s existed! Do you want to remake it?\n",folder_path);
		printf("1. Yes\n2. No\n");
		if (get_choice("Input your choice",1,2) == 1) {
			dir_delete(folder_path);
		} else {
			return;
		}
	}
	dir_make(folder_path);
	printf("Done!\n");
	system("pause");
}

void new_file() {
	system("cls");
	char file_path[255];
	get_user_input(file_path,"Type your file path here");
	if (is_file_exist(file_path)) {
		printf("File %s existed! Do you want to remake it?\n",file_path);
		printf("1. Yes\n2. No\n");
		if (get_choice("Input your choice",1,2) == 1) {
			file_delete(file_path);
		} else {
			return;
		}
	}
	file_make(file_path);
	printf("Done!\n");
	system("pause");
}

void delete_folder() {
	system("cls");
	char folder_path[255];
	get_user_input(folder_path,"Type your folder path here");
	if (is_dir_exist(folder_path)) {
		printf("Do you sure you want to delete folder %s?\n",folder_path);
		printf("1. Yes\n2. No\n");
		if (get_choice("Input your choice",1,2) == 1) {
			dir_delete(folder_path);
		}
	} else {
		printf("Folder %s cannot be found!\n",folder_path);
	}
	printf("Done!\n");
	system("pause");
}

void delete_file() {
	system("cls");
	char file_path[255];
	get_user_input(file_path,"Type your file path here");
	if (is_file_exist(file_path)) {
		printf("Do you sure you want to delete file %s?\n",file_path);
		printf("1. Yes\n2. No\n");
		if (get_choice("Input your choice",1,2) == 1) {
			file_delete(file_path);
		}
	} else {
		printf("File %s cannot be found!\n",file_path);
	}
	printf("Done!\n");
	system("pause");
}
