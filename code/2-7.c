#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* file = fopen("config.txt", "r");
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        char* key = strtok(line, "=");
        char* value = strtok(NULL, "\n");
        if (strcmp(key, "InputFileName") == 0) {
            strncpy(config_ptr->InputFileName, value, sizeof(config_ptr->InputFileName));
            config_ptr->InputFileName[sizeof(config_ptr->InputFileName) - 1] = '\0';
        } else if (strcmp(key, "Options") == 0) {
            config_ptr->Options = atoi(value);
        } else if (strcmp(key, "SectionName") == 0) {
            strncpy(config_ptr->SectionName, value, sizeof(config_ptr->SectionName));
            config_ptr->SectionName[sizeof(config_ptr->SectionName) - 1] = '\0';
        } else if (strcmp(key, "Address") == 0) {
            config_ptr->Address = strtoull(value, NULL, 16);
        }
    }
    fclose(file);

}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

