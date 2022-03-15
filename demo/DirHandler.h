#ifndef DIR_HANDLER_INCLUDED
#define DIR_HANDLER_INCLUDED

int is_dir_exist(char *path);
void dir_make(char *path);
void dir_delete(char *path);
void dir_copy(char *src_path, char *des_path);

#endif
