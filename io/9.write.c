#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


#define BUFFER_SIZE 1024
#define SRC_FILE_NAME "test.txt"
#define DEST_FILE_NAME "demon.txt"
#define OFFSET      1024

int main(int argc, const char *argv[])
{
	int fds, fdd;
	unsigned char buff[BUFFER_SIZE];
	int read_len;

	if((fds = open(SRC_FILE_NAME, O_RDONLY)) < 0) {
		perror("fail to open src_file");
		return -1;
	}
	if((fdd = open(DEST_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0) {
		perror("fail to open desc_file");
		return -1;
	}

	lseek(fds, -OFFSET, SEEK_END);

	while((read_len = read(fds, buff, sizeof(buff))) > 0) {
		write(fdd, buff, read_len);	
	}
	close(fds);
	close(fdd);

	return 0;
}

