#include <stdio.h>
int main(int argc, const char *argv[])
{
	int c;
	while(1) {
		c = fgetc(stdin);
		if((c >= '0') && (c <= '9')) fputc(c, stdout);
		if(c == '\n') break;
	}

	return 0;
}
