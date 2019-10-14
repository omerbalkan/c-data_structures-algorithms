#include <stdio.h> 
#include <stdlib.h> 
#include "structures.h" 

// get string from users via console; 
char* getstring(){
	int size = 8; 
	char* buf = getchars(size); 
	int i = 0; 
	int c; 
	while ((c = fgetc(stdin)) != '\n' && c != EOF){
		if (i == size - 1){
			size *= 2; 
			buf= rechars(buf, size); 
		}
		buf[i++] = c; 
	}
	buf[i++] = 0; 
	if (i < size){
		buf = rechars(buf, i); 
	}
	return buf; 
}

