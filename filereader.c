#include "filereader.h"
void filereader(char *t){
    FILE *file;
    file = fopen(t,"r");
    char str[903];
    int i = 0;
    while (fgets(str, 903, file) != NULL) {
        printf("%s", str, strlen(str));
    }
    fclose(file);
}