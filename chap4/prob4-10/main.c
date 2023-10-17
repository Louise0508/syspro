#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int c;
	int i;

	if (i = 1)
		if (i < argc)
			if (i++) {
				if (argc < 2)
				fp = stdin;
			else
				fp = fopen(argv[i], "r");

	c = fgetc(fp);
	while (c != EOF) {
		fputc(c, stdout);
		c = fgetc(fp);
	}
	fclose(fp);
    }
	return 0;
}
