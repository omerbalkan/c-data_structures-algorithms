#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int length(char* string){
	int counter = 0; 
	while (*string++)
		counter++; 
	return counter; 
}
char* getchars(int size){
	return (char*)malloc(sizeof(char) * size); 
}
char* rechars(char* buf, int resize){
	return (char*)realloc(buf, sizeof(char) * resize); 
}
char* str_cpy(char* string){
	int size = length(string) + 1; 
	char* buf = getchars(size); 
	memcpy(buf, string, size); 
	return buf; 
}
char* str_cat(char* dest, char* src){
	int len1 = length(dest); 
	int len2 = length(src); 
	int size = len1 + len2 + 1; 
	char* buf = getchars(size); 
	memcpy(buf, dest, len1); 
	memcpy(buf + len1, src, len2); 
	buf[size - 1] = 0; 
	return buf; 
}
void str_rev(char* string){
	char* buf = str_cpy(string); 
	int len = length(string); 
	int i = 0; 
	while (len-- > 0){
		string[i++] = buf[len]; 
	}
	free(buf); 
}

char* getchars_zero(int size){
	char* buf = getchars(size); 
	buf[size - 1] = 0; 
	int i = 0;
	while (i < size - 1)
		buf[i++] = '0'; 
	return buf; 
}
char* rechars_front(char* buf, int resize){
	int current_size = length(buf) + 1; 
	if (resize <= current_size)
		return rechars(buf, resize); 
	
	char* new_buf = getchars_zero(resize); 
	int first_index = resize - current_size; 
	memcpy(new_buf + first_index, buf, current_size - 1); 
	free(buf); 
	return new_buf; 
}























