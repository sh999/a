#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
int main(void){
	return execl ("/bin/ls", "ls", NULL);
}
