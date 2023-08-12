#include "file_read.h"

int readFile(const char* name, LinkedListVertex* list) {
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
                parsStr(tmpStr, list);
            }
            fclose(fp);
        } else {
            ret = 1;
        }
    }

    return ret;
}

int parsStr(char* input, LinkedListVertex* list) {
    int ret = 0;
    char* token = 0;

    token = strtok(input, " ");
    if (!strcmp(token, "v")) {
        double tmp[4] = {};
        tmp[3] = 1.;
        int i = 0;
        token = strtok(NULL, " ");
        while (token != NULL) {
            tmp[i++] = atof(token);
            token = strtok(NULL, " ");
        }
        vertexPushBack(list, tmp[0], tmp[1], tmp[2], tmp[3]);
    } else if (!strcmp(token, "f")) {
        while (token != NULL) {
            token = strtok(NULL, " /");
        }
    }
    return ret;
}