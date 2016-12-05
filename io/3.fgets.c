#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int line = 0;
	char buf[128];
	FILE *fp;

	if(argc < 2) {
		printf("Usage :%s <file>\n", argv[0]);
		return -1;
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		perror("fail to fopen");
		return -1;
	}

	while(fgets(buf, 128, fp) != NULL) {
		if(buf[strlen(buf) - 1] == '\n') line++;
	}

	printf("this line of %s is %d\n", argv[1], line);

	return 0;
}
