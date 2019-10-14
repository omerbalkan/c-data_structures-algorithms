#ifndef structures_h
#define structures_h 

typedef struct {
	int rows; 
	int cols; 
	int** matris; 
}matrix; 

typedef struct {
	int x; 
	int y; 
	int z; 
	int*** values; 
}prizma; 

typedef struct {
	int size; 
	int count;  
	int* arr; 
}array; 

typedef struct _item{
	int value;
	struct _item* next; 
}item;

typedef struct {
	int count; 
	item* head; 
}list; 

typedef struct _node{
	int value; 
	struct _node* left; 
	struct _node* right; 
}node; 

typedef struct _edge{
	int dest; 
	int weight; 
	struct _edge* next; 
}edge;

typedef struct {
	int count; 
	edge* head; 
}edgeList; 

typedef struct {
	int vertex; 
	edgeList* neighbors; 
}graph; 

#endif 














