#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int externvar1 = 101; 
int externvar2; 

void print(int sayi){
	printf("%d\n", sayi); 
}
void prints(char* x, int count){
	int i = 0; 
	while (i++ < count)
		printf("%s", x); 
}
int math_pow(int alt, int us){
	int result = 1; 
	int i = 0;  
	while (i++ < us)
		result *= alt; 
	return result; 
}
char* tobinary(int sayi){
	int size = 9; 
	char* buf = getchars_zero(size); 
	int i = 7; 
	while (sayi > 0){
		char c = (char)((sayi % 2) + 48);
		sayi /= 2; 
		
		if (i == -1){
			size += 8 ; 
			buf = rechars_front(buf, size); 
			i = 7; 
		}
		buf[i--] = c; 
	}
	return buf; 
}
char* tobytes(char* binary){
	int len = length(binary); 
	int bytes = len / 8; 
	if (bytes == 1)
		return binary; 
	int resize = len + bytes; 
	char* buf = getchars(resize); 
	
	int i = 0; 
	int index = 0; 
	while (i < bytes){
		memcpy(buf + index, binary + i * 8, 8); 
		buf[index + 8] = ' '; 
		index += 9;
		i++;  
	}
	
	buf[index] = 0; 
	return buf; 
}
int todecimal(char* binary){
	int result = 0; 
	int last_index = length(binary) - 1; 
	int carpan = 1; 
	while (last_index > -1){
		result += carpan * ((int)binary[last_index--] - 48); 
		carpan *= 2; 
	}
	return result; 
}
int basSayisi(int sayi){
	int i = 1; 
	while (sayi > 9){
		i++; 
		sayi /= 10; 
	}
	return i; 
}
char* tostring(int sayi){
	int len = basSayisi(sayi); 
	char* buf = getchars(len+1); 
	buf[len--] = 0; 
	
	while (len > -1){
		buf[len--] = (char)((sayi % 10) + 48); 
		sayi /= 10; 
	}
	return buf;
}






















