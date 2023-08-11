#include "file_read.h"

int readFile(const char* name) {
    FILE* fp;
    int ret = 0;
    const char* pattern = "^.*\\.obj$";

    const char* error;
    int erroffset;

    pcre* re = pcre_compile(pattern, 0, &error, &erroffset, NULL);
    if (re == NULL) {
        printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
        ret = 1;
    } else {
        int regex_found =
            pcre_exec(re, NULL, name, strlen(name), 0, 0, NULL, 0);
        printf("%s\n", name);

        if ((fp = fopen(name, "r")) != NULL && regex_found >= 0) {
            char tmpStr[255] = {};
            while (!feof(fp)) {
                fgets(tmpStr, 255, fp);
                parsStr(tmpStr);
            }
            fclose(fp);
        } else {
            ret = 1;
        }
    }

    return ret;
}

int parsStr(char* input) {
    int ret = 0;
    char* token = 0;

    token = strtok(input, " ");
    if (!strcmp(token, "v")) {
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, " ");
        }
    } else if (!strcmp(token, "f")) {
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, " /");
        }
    }
    return ret;
}