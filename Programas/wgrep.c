#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void buscar_en_archivo(char *termino, FILE *fp);

int main(int argc, char *argv[]) {
    
    if(argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc == 2) {
        buscar_en_archivo(argv[1], stdin);
        exit(0);
    }
    
    FILE *fp;
    for (int i = 2; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        if(fp != NULL){
            buscar_en_archivo(argv[1], fp);
        }
        else{
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        

    }
    fclose(fp);
    return 0;
    
}

void buscar_en_archivo(char *termino, FILE *fp) {
    char *linea = NULL;
    size_t len = 0;
    while(getline(&linea, &len, fp) != -1){
        if (strstr(linea, termino) != NULL) {
            printf("%s", linea);
        }
    }
    free(linea);
    
    
}