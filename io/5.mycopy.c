#include <stdio.h>
#include <errno.h>

#define N 32

int main(int argc, const char *argv[])
{
	size_t n = 0;
	char buf[N];
	FILE *fps, *fpd;
	if(argc <3) {
		printf("Usage :%s<src_file><dst_file>\n", argv[0]);
		return -1;
	}

	if((fps = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "fail to open %s : %s\n", argv[1], strerror(errno));
		return -1;
	}
	if((fpd = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "fail to open %s : %s\n", argv[2], strerror(errno));
		return -1;
	}

	while((n =fread(buf, 1, N, fps)) > 0) {
		fwrite(buf, 1, n, fpd);
	}

	fclose(fps);
	fclose(fpd);

	return 0;
}
