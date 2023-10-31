#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 100

int main() {

    char savedText[MAX_ROWS][MAX_COLS];
    int currentRow = 0;

    FILE *file = fopen("text.txt", "r");

    while (currentRow < MAX_ROWS && fgets(savedText[currentRow], MAX_COLS, file) != NULL)
    {
        currentRow++;
    }

    fclose(file);

    int a;
    printf("Pls 'Enter' the line to select : ");
    scanf("%d", &a);

    if (a >= 1 && a <= currentRow) {
        printf("열 %d:\n", a);
        int i;
        for (i = 0; i < currentRow; i++) 
        {
            printf("%s\n", savedText[i]);
        }
    }
    else {
     printf("error");
    }

    fclose(file);
 
    return 0;
}
