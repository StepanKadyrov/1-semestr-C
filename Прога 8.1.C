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
        int size = strlen(array_words[k]);
        char* tmp = (char*)malloc(size*sizeof(char));
	    for(int i = strlen(array_words[k])-1; i >= 0; i--, j++){
	        *(tmp+j) = *(array_words[k]+i);
	   }
	   *(tmp+j) = '\0';
	   
	   for(int t = k+1; t<n; t++){
    	       if(strlen(array_words[k]) != strlen(array_words[t])){
    	           break;
    	       }
    	       else{
    	           int flag = 1;
        	       for(int i = strlen(array_words[k])-1; i>=0; i--){
        	           if(*(tmp+i) != *(array_words[t]+i)){
        	               flag = 0;
        	           }
        	       }
        	       if(flag){
            	       printf("%s %s \n", array_words[k], array_words[t]);
        	       }
    	       }
	   }
	   
	   free(tmp);
    }
    return 0;
}