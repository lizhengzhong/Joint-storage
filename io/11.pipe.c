#include <unistd.h>
#include <sys/types.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_TIME 256
#define DELAY_TIME 1

int main(int argc, const char *argv[])
{
	pid_t pid;
	int pipe_fd[2];
	char buf[MAX_DATA_TIME];
	const char data[] = "pipe test program";
	int real_read, real_write;

	memset(buf, 0, sizeof(buf));
	/*创建管道*/
	if(pipe(pipe_fd) < 0) {
		perror("fail to pipe");
		exit(-1);
	}
	/*创建一个子进程*/
	if((pid = fork())  == 0) {
		/*子进程关闭写文件描述符，并通过使子进程暂停1s等待父进程关闭相应的读描述符*/
		close(pipe_fd[1]);
		sleep(DELAY_TIME);
		
		/*子进程读取管道内容*/
		if((real_read = read(pipe_fd[0], buf, MAX_DATA_TIME)) > 0) 
			printf("%d bytes read from the pipe is '%s'\n", real_read, buf);
		
		close(pipe_fd[0]); /*关闭进程的读描述符*/
	} else if(pid > 0) {
		/*父进程关闭读描述符*/
		close(pipe_fd[0]);

		if((real_write = write(pipe_fd[1], data, strlen(data))) != -1) 
			printf("parent wrote %d bytes : '%s'\n", real_write, data);
		close(pipe_fd[1]);/*关闭进程的写描述符*/
		waitpid(pid, NULL, 0);/*收集子进程退出信息*/
		exit(0);
	}
	

	return 0;
}



















