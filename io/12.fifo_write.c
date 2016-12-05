#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define MYFIFO    "/tmp/myfifo"  /*有名管道文件名*/

int main(int argc, const char *argv[])
{
	int fd;
	int nwrite;

	if(argc < 2) {
		print("Usage: ./fifo_write string\n");
		exit(-1);
	}

	/*以只写的方式打开FIFO管道*/
	if((fd = open(MYFIFO, O_WRONLY)) < 0) {
		perror("fail to open fifo");
		exit(-1);
	}
	/*向管道中写如字符串*/
	if((nwrite = write(fd, argv[1], strlen(argv[1]) + 1))  > 0)
		printf("write '%s' to FIFO\n", argv[1]);
	close(fd);
		
	
	return 0;
}
