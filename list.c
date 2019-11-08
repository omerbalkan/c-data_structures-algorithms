#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include "structures.h"

item* new_item(int value){
	item* i = (item*)malloc(sizeof(item)); 
	i->value = value; 
	i->next = 0; 
	return i; 
}
list* new_list(){
	list* l = (list*)malloc(sizeof(list)); 
	l->count =0; 
	l->head= 0;
	return l; 
}
void push(list* l, int value){
	item* i = new_item(value); 
	if (l->head == 0)
		l->head = i; 
	else{
		item* iter = l->head; 
		while (iter->next)
			iter = iter->next; 
		iter->next = i; 
	}
	l->count++; 
}
void unshift(list* l, int value){
	item* i = new_item(value); 
	i->next = l->head ; 
	l->head = i; 
	l->count++; 
}
int pop(list* l){
	if (l->count == 0){
		puts("Exception : empty object"); 
		return;
	}
	item* temp = 0; 
	if (l->count == 1){
		temp = l->head; 
		l->head = 0; 
	}
	else{
		item* iter = l->head; 
		while (iter->next->next)
			iter = iter->next; 
		temp = iter->next; 
		iter->next = 0; 
	}
	int result = temp->value; 
	free(temp); 
	l->count--; 
	return result;
}
int shift(list* l){
	if (l->count == 0){
		puts("Exception : empty object"); 
		return;
	}
	item* temp = l->head; 
	l->head = l->head->next; 
	int result = temp->value; 
	free(temp); 
	l->count--; 
	return result ;
}
int getitem(list* l, int index){
	if (index < 0 || index >= l->count){
		puts("Exception : Index Out of Range"); 
		return; 
	}
	int i = 0; 
	item* iter = l->head; 
	while(i++ < index)
		iter = iter->next; 
	return iter->value; 
}
void setitem(list* l, int index, int value){
	if (index < 0 || index >= l->count){
		puts("Exception : Index Out of Range"); 
		return; 
	}
	int i = 0; 
	item* iter = l->head; 
	while(i++ < index)
		iter = iter->next; 
	
	iter->value = value; 
}
char* tostr_list(list* l){
	char* result = str_cpy("["); 
	item* iter = l->head; 
	while (iter){
		char* n = tostring(iter->value); 
		char* add = str_cat(n, ", "); 
		char* old = result; 
		
		result = str_cat(result, add); 
		
		free(n); 
		free(old); 
		free(add); 
		
		iter = iter->next; 
	}
	int len = length(result); 
	if (len == 1){
		free(result); 
		return str_cpy("[]"); 
	}
	result[len-2] = ']';
	result[len-1] = 0; 
	return result; 
}
char* tolist(int count, ...){
	list* l = new_list(); 
	va_list params; 
	va_start(params, count); 
	
	int i = 0; 
	while (i++ < count){
		push(l, (int)va_arg(params, int)); 
	}
	va_end(params); 
	return l; 
}
list* splice(list* l, int start, int size, int count, ...){
	start = start < 0 ? 0 : start;
	int stop = start + size;
	stop = stop > l->count ? l->count : stop;

	list* result = new_list();
	if (stop <= start)
		return result;

	int index = 0;
	item* iter = l->head;
	while (index < start-1){
		iter = iter->next;
		index++;
	}
	va_list params;
	va_start(params, count);
	int i = 0;

	if (start == 0){
		push(result, iter->value);
		if (count > 0){
			iter->value = (int)va_arg(params, int);
			i = 1;
		}
		start++;
	}
	while (start < stop){
		push(result, iter->next->value);
		if (i < count){
			iter->next->value = (int)va_arg(params, int);
			i++;
			iter = iter->next;
		}
		else{
			item* temp = iter->next;
			iter->next = iter->next->next;
			iter = iter->next;
			free(temp);
			l->count--;
		}
		start++;
	}
	va_end(params);
	return result;
}
list* slice(list* x, int start, int stop){
	start = start < 0 ? 0 : start;
	stop = stop > x->count ? x->count : stop;
	list* result = new_list();
	if (stop <= start)
		return result;
	int i = 0;
	item* iter = x->head;
	while (i++ < start){
		iter = iter->next;
	}
	while (start < stop){
		push(result, iter->value);
		start++;
	}
	return result;
} 




















