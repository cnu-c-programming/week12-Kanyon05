#include <stdio.h>

int main(int argc, const char* argv[], const char* envp[]) {
    envp = envp;
    while (*envp) {
        printf("%s\n", *envp);
        envp++;
    }

    return 0;
}
