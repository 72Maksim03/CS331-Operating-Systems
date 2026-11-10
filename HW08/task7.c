#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

ssize_t readChunk(int fd, char buffer[], int size) {
    int total = 0;

    while (total < size) {
        ssize_t n = read(fd, buffer + total, size - total);

        if (n == -1) {
            return -1;
        }

        if (n == 0) {
            break;
        }

        total += n;
    }

    return total;
}

int main() {
    char filename1[256];
    char filename2[256];

    printf("Enter the first file path: ");
    scanf("%255s", filename1);

    printf("Enter the second file path: ");
    scanf("%255s", filename2);

    int fd1 = open(filename1, O_RDONLY);

    if (fd1 == -1) {
        printf("Error opening the first file\n");
        exit(1);
    }

    int fd2 = open(filename2, O_RDONLY);

    if (fd2 == -1) {
        printf("Error opening the second file\n");
        close(fd1);
        exit(1);
    }

    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];

    long long offset = 0;

    while (1) {
        ssize_t bytes1 = readChunk(fd1, buffer1, BUFFER_SIZE);
        ssize_t bytes2 = readChunk(fd2, buffer2, BUFFER_SIZE);

        if (bytes1 == -1 || bytes2 == -1) {
            printf("Error reading files\n");
            close(fd1);
            close(fd2);
            exit(1);
        }

	ssize_t common = bytes1 < bytes2 ? bytes1 : bytes2;

        for (int i = 0; i < common; i++) {
            if (buffer1[i] != buffer2[i]) {
                printf("Files differ at byte %lld\n", offset + i);
                close(fd1);
                close(fd2);
                return 1;
            }
        }

        if (bytes1 != bytes2) {
            printf("Files differ at byte %lld\n", offset + common);
            close(fd1);
            close(fd2);
            return 1;
        }

        if (bytes1 == 0) {
            break;
        }

        offset += bytes1;
    }

    printf("Files are identical\n");

    close(fd1);
    close(fd2);

    return 0;
}

