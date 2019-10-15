#include <stdio.h> 
#include <stdlib.h> 

int linearsearch(int arr[], int len,  int x){
	int i = 0; 
	while (i < len && arr[i] != x)
		i++; 
	return i == len ? -1 : i; 
}
int binarysearch(int arr[], int len, int x){
	int left = 0; 
	int right = len - 1; 
	
	while(left <= right){
		int m = (left + right) / 2; 
		if (arr[m] == x)
			return m; 
		if (arr[m] > x)
			right = m-1; 
		else 
			left = m+1; 
	}
	return -1; 
}
int jumpsearch(int arr[], int len, int x){
	int step = sqrt(len); 
	int i = 0; 
	int forward = 0; 
	int backward = 0; 
	while (i < len){
		if (arr[i] == x)
			return i;
		if (arr[i] > x){
			backward = 1; 
			break; 
		}
		if (i + step >= len){
			forward = 1; 
			break; 
		}
		i += step; 
	}
	if (forward){
		while (++i < len){
			if (arr[i] == x)
				return i;  
		}
	}
	if (backward){
		int stop = i - step; 
		while (--i > stop){
			if (arr[i] == x)
				return i; 
		}
	}
	return -1; 
}


















