#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include "structures.h"

int findIndex(char* string, char* search){
	int len1 = length(string); 
	int len2 = length(search); 
	
	int i = 0; 
	int first_char = search[0]; 
	int last = len1 - len2 + 1; 
	while (i < last){
		if (string[i] == first_char && memcmp(string + i, search, len2) == 0)
			return i; 
		i++; 
	}
	return -1; 
}
list* findIndexes(char* string, char* search){
	int len1 = length(string); 
	int len2 = length(search); 
	
	int i = 0; 
	int first_char = search[0]; 
	int last = len1 - len2 + 1; 
	list* indexes = new_list(); 
	while (i < last){
		if (string[i] == first_char && memcmp(string + i, search, len2) == 0){
			push(indexes, i); 
			i += len2; 
		}
		else
			i++; 
	}
	return indexes; 
}
char* substring(char* string, int start, int stop){
	int len = length(string); 
	start = start < 0 ? 0 : start; 
	stop = stop > len ? len : stop; 
	
	if (stop <= start)
		return str_cpy(""); 
	
	int size = stop - start + 1; 
	char* buf =getchars(size); 
	
	memcpy(buf, string + start, size-1); 
	buf[size-1] = 0; 
	return buf; 
	
}
char** split(char* string, char* sep){
	list* indexes = findIndexes(string, sep); 
	char** words = (char**)malloc(sizeof(char*) * (indexes->count + 2)); 
	words[indexes->count + 1] = 0; 
	
	int len1 = length(string); 
	int len2 = length(sep); 
		
	int index = 0; 
	int start = 0; 
	push(indexes, len1); 
	
	item* stop = indexes->head; 
	int i = 0; 
	while(stop){
		words[i++] = substring(string, start, stop->value); 
		index += stop->value - start; 
		
		start = stop->value + len2; 
		
		item* temp = stop; 
		stop = stop->next;
		free(temp); 
	}
	free(indexes); 
	return words; 
}
char* remove_str(char* string, char* old){
	int len1 = length(string); 
	int len2 = length(old); 
	
	list* indexes = findIndexes(string, old); 
	if (indexes->count == 0)	
		return str_cpy(string); 
	
	int size = len1 - (indexes->count * len2) + 1; 
	char* buf = getchars(size); 
	
	int index = 0; 
	int start = 0; 
	
	item* stop = indexes->head; 
	while (stop){
		memcpy(buf + index, string + start, stop->value - start); 
		index += stop->value - start; 
		
		start = stop->value + len2; 
		
		item* temp = stop; 
		stop = stop->next; 
		free(temp); 
	}
	memcpy(buf+index, string + start, len1 - start); 
	buf[size-1] = 0; 
	return buf; 
}
char* replace(char* string, char* old, char* _new){
	int len1 = length(string); 
	int len2 = length(old); 
	
	list* indexes = findIndexes(string, old); 
	if (indexes->count == 0)	
		return str_cpy(string); 
	int len3 = length(_new); 
	int size = len1 + indexes->count * (len3 - len2) + 1;  
	char* buf = getchars(size); 
	
	int index = 0; 
	int start = 0; 
	
	item* stop = indexes->head; 
	while (stop){
		memcpy(buf + index, string + start, stop->value-start); 
		index += stop->value - start; 
		memcpy(buf + index, _new, len3); 
		index += len3; 
		
		start = stop->value + len2; 
		
		item* temp = stop; 
		stop = stop->next; 
		free(temp); 
	}
	memcpy(buf + index, string + start, len1 - start); 
	free(indexes); 
	return buf; 
}
char* trim(char* string, char* old){
	int len = length(string); 
	int len2 = length(old); 
	
	int start = 0; 
	while (memcmp(string + start, old, len2) == 0)
		start += len2; 
	int stop = len; 
	while (memcmp(string + stop - len2, old, len2) == 0)
		stop -= len2; 
	
	return substring(string, start, stop); 
}
char* join(char* sep, int count, ...){
	va_list params; 
	va_start(params, count); 
	
	char* result = str_cpy((char*)va_arg(params, char*)); 
	int i = 1; 
	while (i++ < count){
		char* toadd = str_cat(sep, (char*)va_arg(params, char*));
		char* old = result; 
		
		result = str_cat(result, toadd); 
		
		free(toadd); 
		free(old); 
	}
	va_end(params); 
	return result; 
}
char* join2(char* sep, int count, ...){
	va_list params; 
	va_start(params, count); 
	
	char* result = str_cpy(""); 
	int i = 0; 
	while (i++ < count){
		char* toadd = str_cat((char*)va_arg(params, char*), sep);
		char* old = result; 
		
		result = str_cat(result, toadd); 
		
		free(toadd); 
		free(old); 
	}
	va_end(params); 
	result = trim(result, sep); 
	return result; 
}

















