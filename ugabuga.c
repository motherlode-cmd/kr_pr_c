#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* read_word() {
    int size = 10;
    int length = 0;
    char *word = malloc(size*sizeof(char));
    int c;
    c = getchar();
	while (c != ' ' && c != '\n'){
	  	word[length++] = c;
	    if(length == size - 2){
	    	size += length + 2;
	    	word = realloc(word, size);
	    }
	    c = getchar();
	}
	word[length] = '\0';
	return word;
}

int main() {
	int len_arr = 20;
	char** dict = malloc(len_arr * sizeof(char*));
	char** text = malloc(len_arr * sizeof(char*));	
	for(int i = 0; i < len_arr; i++) {
		dict[i] = malloc(len_arr * sizeof(char));
		text[i] = malloc(len_arr * sizeof(char));
	}
	int num = 0;
	dict[num] = read_word();
	while(strcmp(dict[num], "ugabuga")){
		num++;
		dict[num] = read_word();
		if(num == len_arr - 1) {
			len_arr += len_arr;
			char** temp = realloc(dict, len_arr * sizeof(char*));
			dict = temp;
		}
	}
	int size = num;
	num = 0;
	text[num] = read_word();
	text[num] = read_word();
	while(strcmp(text[num], "")){
		num++;
		text[num] = read_word();
		if(num == len_arr - 1) {
			len_arr += len_arr;
			char** temp = realloc(text, len_arr * sizeof(char*));
			text = temp;
		}
	}
	for(int i = 0; i < num; i++) {
		for(int j = 0; j < size; j += 2) {
			if(strcmp(dict[j], text[i]) == 0) {
				printf("\n%s ", dict[j + 1]);
				break;
			}
		}
	}
	return 0;
}
