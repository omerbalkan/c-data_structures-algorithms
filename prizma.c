#include <stdio.h>
#include <stdlib.h> 
#include "structures.h" 
prizma* new_prizma(int x, int y, int z){
	prizma* p = (prizma*)malloc(sizeof(prizma)); 
	p->x = x; 
	p->y = y; 
	p->z = z; 
	
	p->values = (int***)malloc(sizeof(int**) * z); 
	int i = 0; 
	while (i < z)
		*(p->values + i++) = (int**)malloc(sizeof(int*) * y); 
	i = 0; 
	int j;
	while (i < z){
		j = 0; 
		while (j < y){
			*(*(p->values + i) + j++) = (int*)malloc(sizeof(int) * x); 
		}
		i++; 
	}
	int k = 0; 
	for (i=0; i<z; i++){
		for (j=0; j<y; j++){
			for (k=0; k<x; k++){
				p->values[i][j][k] = (i+1) * (j+1) * (k+1); 
			}
		}
	}
	return p; 
}
void print_prizma(prizma* p){
	int i,j,k;
	for (i=0; i<p->z; i++){
		for (j=0; j<p->y; j++){
			for (k=0; k<p->x; k++){
				printf("%-6d", p->values[i][j][k]); 
			}
			puts(""); 
		}
		puts("\n"); 
	}
}



















