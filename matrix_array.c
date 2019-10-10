#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

//matrix* new_matrix(int rows, int cols){
//	matrix* m = (matrix*)malloc(sizeof(matrix)); 
//	int* x = (int*)m; 
//	*x = rows; 
//	*(++x) = cols;
//	m->matris = (int**)malloc(sizeof(int*) * rows); 
//	int** matris = m->matris; 
//	int i = 0; 
//	while (i < rows)
//		*(matris + i++) = (int*)malloc(sizeof(int) * cols);  
//	
//	int* satir = *matris; 
//	int j; 
//	i = 0; 
//	while (i < rows){
//		j = 0; 
//		while (j < cols){
//			*(satir + j) = (i+1) * (j+1); 
//			j++; 
//		}
//		satir = *(matris + ++i);  
//	}
//	return m; 
//}
matrix* new_matrix(int rows, int cols){
	matrix* m = (matrix*)malloc(sizeof(matrix)); 
	m->rows = rows; 
	m->cols = cols; 
	m->matris = (int**)malloc(sizeof(int*) * rows); 
	int i = 0; 
	while (i < rows)
		*(m->matris + i++) = (int*)malloc(sizeof(int) * cols); 
	int j; 
	for (i = 0; i<rows; i++){
		for (j=0; j<cols; j++){
			*(*(m->matris + i) + j) = (i+1) * (j+1); 
		}
	}
	return m; 
}

void print_matrix(matrix* m){
	int i,j; 
	for (i=0; i<m->rows; i++){
		for (j=0; j<m->cols; j++){
			printf("%-3d", *(*(m->matris + i) + j)); 
		}
		puts(""); 
	}
}
array* new_array(){
	array* a = (array*)malloc(sizeof(array)); 
	a->size = 4; 
	a->count = 0; 
	a->arr = (int*)malloc(sizeof(int) * 4); 
	return a; 
}
void append(array* a, int value){
	if (a->count == a->size){
		a->size += 4; 
		a->arr = (int*)realloc(a->arr, a->size); 
	}
	*(a->arr + a->count++) = value; 
}

















