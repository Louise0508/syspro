#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char buffer[500];
    char ch;
    int fd1;
    int fd2;
    if ((fd1 = open(argv[1], O_RDONLY)) == 0) {
        perror(argv[1]);
        exit(1);
    }
    if ((fd2 = open(argv[2], O_WRONLY)) == 0) {
        perror(argv[2]);
        exit(1);
    }
    int loc;
    int i = 0;

    if ((loc = lseek(fd1, -sizeof(char), SEEK_END)) < 0) return -1;
    while (loc >= 0) {
        read(fd1, &ch, sizeof(char));
        buffer[i++] = ch;
        if (ch == '\n') {
            int j = i;
            for (i -2; j >= 0; j--) {
                write(fd2, &(buffer[j]), sizeof(char));
            }
            write(fd2, "\n", sizeof(char));
            i = 0;
        }
        loc = lseek(fd1, -2 * sizeof(char), SEEK_CUR);
    }
    int j = i;
    for (i - 1; j >= 0; j--) {
        write(fd2, &(buffer[j]), sizeof(char));
    }
    write(fd2, "\n", sizeof(char));
    close(fd1);
    close(fd2);

    return 0;
}
