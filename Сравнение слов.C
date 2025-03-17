#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 100
char** make_array_words(char*, int*); // функция, которая на вход принимает предложение и возращает массив из слов этого предложения
void words_compare(char*, char*); // функция побуквенного сравнения слов

int main(){
    char array[N];
    printf("Vvedite predlozhenie: ");
    gets(array);//вводим наше предложение
    
    int number_of_words = 0;
    char** array_words = make_array_words(array, &number_of_words); // разбиваем его на слова
    int i, k;
    
    for(i = 0; i < number_of_words; i++){
        for(k = i + 1; k < number_of_words; k++){
            words_compare(*(array_words+i), *(array_words+k));
        }
    }
    
    return 0;
}

char** make_array_words(char* array, int* number_of_words){
    
    //считаем количество слов в предложении:
    char* copy_array = (char*)malloc(N * sizeof(char));
    strcpy(copy_array,array);
    char* word = strtok(copy_array, " ,.;:'\"");
    while(word != '\0'){
        word = strtok(NULL," ,.;:'\"");
        (*number_of_words)++;
    }
    
    //выделяем память под количество слов в предложении:
    char** array_words = (char**)malloc(*number_of_words * sizeof(char*));
    
    //создаём массив слов
    word = strtok(array, " ,.;:'\"");
    for(int i = 0; i < *number_of_words; i++){
        *(array_words + i) = (char*)malloc(strlen(word) * sizeof(char));
        strcpy(*(array_words + i), word);
        word = strtok(NULL," ,.;:'\"");
    }
    
    return array_words;
}

void words_compare(char* a, char* b){
    //выбираем длину более короткого из двух слов
    int n = 0;
    if(strlen(a) < strlen(b)){
        n = strlen(a);
    }
    else{
        n = strlen(b);
    }
    
    int k = 0;
    for(int i = 0; i < n; i++){
        if(*(a+i) == *(b+i)){
            k++;
        }
    }
    
    if(k != 0){
    printf("Words \"%s\" and \"%s\" have %d character first\n", a, b, k);
    }
    else{
        printf("Words \"%s\" and \"%s\" have not same character first\n", a, b);
    }
    
}