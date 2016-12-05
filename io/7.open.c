#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, const char *argv[])
{
	int fd;
	if((fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC)) < 0) {
		perror("fail to open");
		return -1;
	}

	close(fd);
	return 0;
}
