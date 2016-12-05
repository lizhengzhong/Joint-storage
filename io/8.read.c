#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 64

int main(int argc, const char *argv[])
{
	int fd, nbyte, sum = 0;
	char buf[N];

	if((fd = open("test.txt", O_RDONLY)) < 0) {
		perror("fail to open");
		return -1;
	}

	while((nbyte = read(fd, buf, N)) > 0) {
		sum += nbyte;
	}

	printf("the lenght of test.txt is %d\n", sum);

	close(fd);
	return 0;
}
