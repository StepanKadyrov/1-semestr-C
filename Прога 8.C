/*В заданном тексте найти все пары слов, из которых одно является обращением другого
(обращение – слово, получающееся из исходного записью его букв в обратном порядке).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int main()
{
    char str[N];
    printf("Введите строку, с количеством символов не больше %d: ", N); 
    fgets(str, N, stdin);
    char * array_words[N];
    int n = 0;
    char * word = strtok(str," ,.;:'\"");
    while(word != NULL){
        array_words[n] = (char*)malloc((strlen(str))*sizeof(char));
        strcpy(array_words[n], word);
        word = strtok(NULL," ,.;:'\"");
        n++;
    }
    
    for(int k = 0; k < n; k++){
        int j = 0;
	   for(int t = k+1; t<n; t++){
    	       if(strlen(array_words[k]) != strlen(array_words[t])){
    	           break;
    	       }
    	       else{
    	           int flag = 1;
    	           int r = 0;
        	       for(int i = strlen(array_words[t])-1; i>=0; i--, r++){
        	           if(*(array_words[k]+r) != *(array_words[t]+i)){
        	               flag = 0;
        	           }
        	       }
        	       if(flag){
            	       printf("Слово и его обращение: %s %s \n", array_words[k], array_words[t]);
        	       }
    	       }
	   }
    }
    for(int y = 0; y < n; y++){
           free(array_words[y]);
    }
    return 0;
}