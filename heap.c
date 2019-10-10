#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

void bubbleDown(list* liste, int index){
	if(index < 0 || index >= liste->count - 1)
		return; 
	int value =getitem(liste, index); 
	int childIndex; 
	
	while ((childIndex = 2 * index + 1) < liste->count){
		int childValue = getitem(liste, childIndex); 
		int nextValue; 
		if (childIndex + 1 < liste->count && (nextValue = getitem(liste, childIndex + 1)) < childValue){
			childValue = nextValue; 
			childIndex++; 
		}
		if (value > childValue){
			setitem(liste, index, childValue); 
			setitem(liste, childIndex, value); 
			
			index = childIndex;
		}
		else 
			break; 
	}
}
void bubbleUp(list* liste, int index){
	if (index < 1 || index >= liste->count)
		return;
	int value = getitem(liste, index); 
	int parentIndex; 
	int parentValue; 
	
	while ((parentIndex = (index-1) / 2) >= 0 && (parentValue = getitem(liste, parentIndex)) > value){
		setitem(liste, index, parentValue); 
		setitem(liste, parentIndex, value); 
		
		index = parentIndex; 
	}
}
void heapAdd(list* liste, int value){
	push(liste, value); 
	bubbleUp(liste, liste->count - 1); 
}
list* heapSort(list* liste){
	list* result = new_list(); 
	while(liste->count > 0){
		push(result, getitem(liste, 0));
		setitem(liste, 0, getitem(liste, liste->count - 1)); 
		pop(liste); 
		bubbleDown(liste, 0); 
	}
	free(liste); 
	return result;
}


















