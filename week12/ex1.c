#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>  

int main()
{
	char string[20];
	int file =  open("/dev/random",  O_RDONLY);
	read(file,string,20);
	printf("%s\n", string);


}	