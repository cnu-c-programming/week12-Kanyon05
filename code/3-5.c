#include <stdio.h>

int main(int argc, const char *argv[]) {
    const char* filename = "numbers.txt";
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) return 0;

    int sum = 0;
    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
    }
    if (ferror(fp)) {
        fprintf(stderr, "invalid input\n");
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
