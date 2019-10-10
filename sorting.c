#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

void swap(int* x, int * y){
	int temp = *x ; 
	*x= *y; 
	*y = temp; 
}
void insertionsort(int dizi[], int len){
	int i,j; 
	for (i=0; i<len-1; i++){
		for (j=i+1; j>0; j--){
			if (dizi[j] < dizi[j-1])
				swap(dizi + j, dizi +j -1); 
			else
				break; 
		}
	}
}
void selectionsort(int dizi[], int len){
	int i,j; 
	for (i=0; i<len-1; i++){
		int minIndex = i; 
		for (j=i+1; j<len; j++){
			if (dizi[j] < dizi[minIndex])	
				minIndex = j; 
		}
		if (i != minIndex)
			swap(dizi + i, dizi + minIndex); 
	}
}
void bubblesort(int dizi[], int len){
	int i,j; 
	for (i=1; i<len; i++){
		for (j=0; j<len-i; j++){
			if (dizi[j] > dizi[j+1])
				swap(dizi + j, dizi +j+1); 
		}
	}
}
void mergesort(int dizi[], int len){
	merge_sort(dizi, 0, len-1); 
}
void merge_sort(int dizi[], int l, int r){
	if(l<r){
		int m = (l+r)/2; 
		merge_sort(dizi, l, m);
		merge_sort(dizi, m+1, r); 
		
		merge(dizi, l, m, r); 
	}
}
void merge(int dizi[], int l, int m, int r){
	int n1 = m -l +1; 
	int n2 = r- m; 
	
	int left[n1]; 
	int right[n2]; 
	
	int i =0, j=0, k=l; 
	while (i < n1)
		left[i++] = dizi[k++]; 
	while (j<n2)
		right[j++] = dizi[k++];
	i = 0; 
	j = 0; 
	k = l; 
	
	while(i < n1 && j < n2)
		dizi[k++] = left[i] < right[j] ? left[i++] : right[j++]; 
	
	while (i < n1)
		dizi[k++] = left[i++]; 
	while (j < n2)
		dizi[k++] = right[j++]; 
}
void quicksort(int dizi[], int len){
	quick_sort(dizi, 0, len -1); 
	
}
void quick_sort(int dizi[], int l, int r){
	if (l < r){
		int q = partition(dizi, l, r); 
		
		quick_sort(dizi, l, q-1); 
		quick_sort(dizi, q+1, r); 
	}
}
int partition(int dizi[], int l, int r){
	int pivot_val = dizi[l]; 
	int pivot_index = l; 
	
	int i = ++l; 
	while (i <= r){
		if (dizi[i] <= pivot_val){
			if (i != l)
				swap(dizi +i, dizi + l); 
			l++; 
		}
		i++; 
	}
	if (pivot_index != --l)
		swap(dizi + pivot_index, dizi + l); 
	return l; 
}
void quicksort2(int dizi[], int len){
	quick_sort2(dizi, 0, len -1); 
	
}
void quick_sort2(int dizi[], int l, int r){
	if (l < r){
		int q = partition2(dizi, l, r); 
		
		quick_sort2(dizi, l, q-1); 
		quick_sort2(dizi, q+1, r); 
	}
}
int partition2(int dizi[], int l, int r){
	int pivot_val = dizi[r]; 
	int i = l; 
	
	while (i < r){
		if (dizi[i] <= pivot_val){
			if (i!=l)
				swap(dizi + i, dizi + l); 
			l++; 
		}
		i++; 
	}
	if (l != r)
		swap(dizi + l, dizi + r); 
	return l;
}















