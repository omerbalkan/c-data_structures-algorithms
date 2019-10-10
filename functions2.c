#include <stdio.h> 
#include <stdlib.h> 

char* processString(char* string, int(*predicate)(int)){
	int len = length(string); 
	char* buf = getchars(len + 1); 
	int i = 0; 
	while (*string){
		if (predicate(*string))
			buf[i++] = *string; 
		string++;  
	}
	if (i < len)	
		buf = rechars(buf, i + 1); 
	buf[i] = 0; 
	return buf; 
}

















