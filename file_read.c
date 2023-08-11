#include "file_read.h"

#include <string.h>

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
            char spec[255] = {};
            double x = 0;
            double y = 0;
            double z = 0;
            double w = 0;

            while (!feof(fp)) {
                fscanf(fp, "%s %lf %lf %lf %lf", spec, &x, &y, &z, &w);
                if (!strcmp(spec, "v") || !strcmp(spec, "f"))
                    printf("%s %lf %lf %lf %lf\n", spec, x, y, z, w);
            }
            fclose(fp);
        } else {
            ret = 1;
        }
    }

    return ret;
}