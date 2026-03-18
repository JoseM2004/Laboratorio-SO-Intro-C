#include <stdio.h>
#include <stdlib.h>

void leer_archivo(char *path);
int main(int argc, char *argv[]) {
 
    if (argc == 1) {
        exit(0);
    }
 
    for (int i = 1; i < argc; i++) {

        leer_archivo(argv[i]);
        
    }
 
    return 0;
}

void leer_archivo(char *path){
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    fclose(fp);    
}
