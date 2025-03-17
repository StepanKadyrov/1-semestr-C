/*В заданном тексте найти все пары слов, из которых одно является обращением другого
(обращение – слово, получающееся из исходного записью его букв в обратном порядке).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file(char *name, char **string, int *len);//функция считывания строки из файла
void string_length(FILE *file, int *len);//функция подсчёта длины строки из файла
void read_string(FILE *file, char *string);//функция считывания строки
int count_word(char *str);//функция, считающая количество слов в строке. Передавать только копию, так как она ломает начальную строку
char **make_array_of_words(char *string, char **words, int len, int* k);
void search_inverse(char **words, int n);

int main(){
    char *string;
    int len = 0;//длина начальной строки
    int error = read_file("Input.txt", &string, &len);
    
    if(!error){
        char **words;
        int k = 0;
        words = make_array_of_words(string, words, len, &k);
        search_inverse(words, k);
    }
    else{
        printf("File error!\n");
    }
    
}

int read_file(char *name, char **string, int *len){
    int f = 0;
    FILE *file = fopen(name, "r");
    if(file == NULL){
        f = 1;
    }
    else{
        string_length(file, len);
        *string = malloc((*len + 1) * sizeof(char));
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
        *(string + i++) = (char) c;
    }
}
int count_word(char *str){
    int count = 0;
    int i = 0;
    char *word = strtok(str," ,.;:'\"");
    
    while (word != NULL)
    {
        word = strtok(NULL," ,.;:'\"");
        count++;
    }

    return count;
}
char **make_array_of_words(char *string, char **words, int len, int* k){
    char *copy_string;
    copy_string = malloc((len + 1) * sizeof(char));
    strcpy(copy_string, string);
    int count = count_word(copy_string);//считаем количество слов в изначальной строке;
    words = (char**)malloc(count * sizeof(char*));
    strcpy(copy_string, string);
    char *word = strtok(copy_string, " ,.;:'\"");
    
    while(*k < count){
        *(words + *k) = (char*)malloc(strlen(word) * sizeof(char));
        *(words + *k) = word;
        word = strtok(NULL," ,.;:'\"");
        *k = *k + 1;
    }
    return words;
}
void search_inverse(char **array_words, int n){
    FILE *Output = fopen("Output.txt", "w");
    for(int k = 0; k < n; k++){
    int j = 0;
	  for(int t = k+1; t<n; t++){
    	   if(strlen(*(array_words+k)) != strlen(*(array_words+t))){
    	       break;
    	   }
    	   else{
    	       int flag = 1;
    	       int r = 0;
        	   for(int i = strlen(*(array_words + t))-1; i >= 0; i--, r++){
        	       if(*(*(array_words + k)+r) != *(*(array_words + t)+i)){
        	           flag = 0;
        	       }
        	   }
        	   if(flag){
            	   fprintf(Output,"Слово и его обращение: %s %s \n", *(array_words + k), *(array_words + t));
        	   }
    	   }
	   }
    }
}