#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct text {
	char text[20];
};

int main()
{
	struct text rec;
	FILE* fp = fopen("out.txt","w");
	char i[10];
	char j[10];

	scanf("%s",i);

		if (strcmp(i, "write 0"))	
		{
			fp = fopen("out.txt", "w");
			printf("%-7s", "text");
			while (scanf("%s", rec.text)==3)
				fprintf(fp, "%s ", rec.text);
			fclose(fp);
			return 0;

		}

		else if (strcmp(i, "write 1") == 0) {
			fp = fopen("out.txt", "a");
			printf("%-7s", "text");
			while (scanf("%s", rec.text)==3)
				fprintf(fp, "%s ", rec.text);
			fclose(fp);
			return 1;
		}

		else {
			exit(0);
		}
}
	

