# FileDir
C is a powerful programming language for operating and interacting with the Window OS. In C, we can directly run window commands (normally use in cmd, powershell or terminal) by the `system(char *command)` function. Thus, we can take its advantage to easily manipulate folders and files. This homemade library is dedicated to provide you some simple operations that implement the idea above.

##### Project Structure
My project supplies you the **FileDir** library as well as a demo project to show you how to use it. If you use **DevC++** IDE, you can open the `.dev` file to understand the stucture of each one.
- Folder `lib` contains the library.
- Folder `demo` contains the demo project.

##### API
The library is consisted of three parts:
- `FileDirHandler.h` - contains some general variables, it does not have any function so that you needn't include it.
- `FileHandler.h` - file handling functions
    - `int is_file_exist(char *path)` - check whether the file is existed or not. `path` is the file's path.
    - `void file_make(char *path)` - create a file at `path`.
    - `void file_delete(char *path)` - delete the `path` file.
    - `void file_copy(char *src_path, char *des_path)` - copy `src_path` file to `des_path` folder.
- `DirHandler.h` - directory (folder) handling functions
    - `int is_dir_exist(char *path)` - check whether the folder is existed or not. `path` is the folder's path.
    - `void dir_make(char *path)` - create new folder at `path`.
    - `void dir_delete(char *path)` - delete folder `path`.
    - `void dir_copy(char *src_path, char *des_path)` - copy folder (and all child folders and files inside) from `src_path` to `des_path`.

##### Quick Demonstration
Let say, we have a folder locating at `C:\QuickDemoSrc\target_folder`. We want to move the `target_folder` folder to `C:\QuickDemoDes` and remember the `target_folder` has some child folders and files in it.

This is a quick example for copying folder:
```
#include <stdio.h>
#include "DirHandler.h"
#include "FileHandler.h"

char *src_path = "C:\\QuickDemoSrc\\target_folder";
char *des_path = "C:\\QuickDemoDes";
char *example_folder_path = "C:\\QuickDemoSrc\\target_folder\\example";
char *example_file_path1 = "C:\\QuickDemoSrc\\target_folder\\example1.txt";
char *example_file_path2 = "C:\\QuickDemoSrc\\target_folder\\example2.txt";
char *example_file_path3 = "C:\\QuickDemoSrc\\target_folder\\example\\example3.txt";

/*
	Create the example
*/
void create_environment() {
	dir_make(src_path);
	dir_make(des_path);
	dir_make(example_folder_path);
	file_make(example_file_path1);
	file_make(example_file_path2);
	file_make(example_file_path3);
}

int main() {
	create_environment();
	dir_copy(src_path,des_path); // Copy the folder
	return 0;
}
```
You may see the `demo` for more information.
