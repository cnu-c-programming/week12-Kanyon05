#include <stdio.h>

int main(int argc, const char *argv[]) {
    const char* filename = "numbers.txt";
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) return 0;

    int sum = 0;
    
    while (!feof(fp)) {
        int num;
        char line[100];
        if (fgets(line, sizeof(line), fp) != NULL) {
            if (sscanf(line, "%d", &num) == 1) {
                sum += num;
            } else {
                fprintf(stderr, "invalid input %s", line);
            }
        }
    }
    

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
