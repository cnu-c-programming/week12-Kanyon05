#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2) return 0;

    FILE* fp = fopen(argv[1], "r");

    for (char c= 'a'; c <= 'z'; c++) {
        int count = 0;
        for (char d; (d = fgetc(fp)) != EOF; ) {
            if (d == c) count++;
        }
        printf("%c: %d\n", c, count);
        rewind(fp);
    }
    
    fclose(fp);
}
