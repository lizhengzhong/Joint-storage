#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE *fp;
	if(argc < 2) {
		printf("Usage :%s <file>\n", argv[0]);
		return -1;
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		perror("fail to open");
		return -1;
	}

		fseek(fp, 0, SEEK_END);
		printf("this size of %s is %ld\n", argv[1], ftell(fp));

		return 0;
}
