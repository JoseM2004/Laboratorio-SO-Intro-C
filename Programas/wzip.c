#include <stdio.h>
#include <stdlib.h>
 
void comprimir(FILE *fp, int *char_actual, int *conteo);
 
int main(int argc, char *argv[]) {
 
    if (argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
 
    int char_actual = -1;
    int conteo = 0;
 
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        comprimir(fp, &char_actual, &conteo);
        fclose(fp);
    }
 
    if (conteo > 0) {
        fwrite(&conteo, sizeof(int), 1, stdout);
        fwrite(&char_actual, sizeof(char), 1, stdout);
    }
 
    return 0;
}
 

void comprimir(FILE *fp, int *char_actual, int *conteo) {
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == *char_actual) {
            (*conteo)++;
        } else {
            
            if (*conteo > 0) {
                fwrite(conteo, sizeof(int), 1, stdout);
                fwrite(char_actual, sizeof(char), 1, stdout);
            }
            *char_actual = c;
            *conteo = 1;
        }
    }
}