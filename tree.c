#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

node* new_node(int value){
	node* n = (node*)malloc(sizeof(node)); 
	n->value = value; 
	n->left = 0; 
	n->right = 0; 
	return n; 
}
node* add(node* r, int value){
	if (r==0)
		return new_node(value); 
	if (value > r->value){
		r->right = add(r->right, value); 
		return r; 
	}
	if (value < r->value){
		r->left = add(r->left, value); 
		return r; 
	}
	else
		return r; 
}
int findMax(node* r){
	while (r->right)
		r = r->right; 
	return r->value; 
}
int findMin(node* r){
	while (r->left)
		r = r->left; 
	return r->value; 
}
node* removeTree(node* r, int value){
	if (r == 0)	
		return 0; 
	if (value == r->value){
		if (r->right == 0 && r->left == 0){
			free(r); 
			return 0; 
		}
		if (r->right != 0){
			int min = findMin(r->right); 
			r->value = min; 
			r->right = removeTree(r->right, min); 
			return r;
		}
		else{
			int max = findMax(r->left); 
			r->value = max; 
			r->left = removeTree(r->left, max); 
			return r; 
		}
	}
	if (value > r->value){
		r->right = removeTree(r->right, value); 
		return r; 
	}
	else{
		r->left = removeTree(r->left, value);
		return r; 
	}
}
void traverse(node* r){
	if (r){
		traverse(r->left); 
		printf("%d ",r->value); 
		traverse(r->right); 
	}
}


















