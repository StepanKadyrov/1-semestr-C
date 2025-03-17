#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file(char *name, char **string);//функция считывания строки из файла
void string_length(FILE *file, int *len);//функция подсчёта длины строки
void read_string(FILE *file, char *string);//функция считывания строки

int main(){
    
    char *string;
    int error = read_file("Input.txt", &string);
    if(!error){
        
    }
    else{
        printf("File error!\n");
    }
    
}

int read_file(char *name, char **string){
    int f = 0;
    int len = 0;
    FILE *file = fopen(name, "r");
    if(file == NULL){
        f = 1;
    }
    else{
        string_length(file, &len);
        *string = malloc((len + 1) * sizeof(char));
        read_string(file, *string);
        fclose(file);
    }
    return f;
}

void string_length(FILE *file, int *len){
    int c;
        while ((c = fgetc(file)) != EOF && c != '\n'){
            *len = *len + 1;
        }
    rewind(file);
}

void read_string(FILE *file, char *string){
    int c;
    int i = 0;
    while ((c = fgetc(file)) != EOF && c != '\n'){
        *(string+ i++) = (char) c;
    }
}