#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define N 64

int main(int argc, const char *argv[])
{
	int n;
	char buf[N];
	FILE *fp;
	time_t t;

	if(argc < 2) {
		printf("Usage : %s <file>\n", argv[0]);
		return -1;
	}

	if((fp = fopen(argv[1], "w")) == NULL) {
		perror("fail to fopen");
		return -1;
	}

	while(1) {
		time(&t);
		fprintf(fp, "%s\n", ctime(&t));
		sleep(1);
		fflush(fp);
	}
	fclose(fp);

	return 0;
}
