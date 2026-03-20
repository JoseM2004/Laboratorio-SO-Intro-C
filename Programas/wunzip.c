#include <stdio.h>
#include <stdlib.h>

void descomprimir(FILE *fp);

int main(int argc, char *argv[]) {

    if (argc == 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        descomprimir(fp);
        fclose(fp);
    }

    return 0;
}

void descomprimir(FILE *fp) {
    int conteo;
    char c;
    
    while (fread(&conteo, sizeof(int), 1, fp) == 1 &&
           fread(&c, sizeof(char), 1, fp) == 1) {
        for (int i = 0; i < conteo; i++) {
            printf("%c", c);
        }
    }
}