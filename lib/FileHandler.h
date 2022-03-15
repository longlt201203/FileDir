#ifndef FILE_HANDLER_INCLUDED
#define FILE_HANDLER_INCLUDED

int is_file_exist(char *path);
void file_make(char *path);
void file_delete(char *path);
void file_copy(char *src_path, char *des_path);

#endif
