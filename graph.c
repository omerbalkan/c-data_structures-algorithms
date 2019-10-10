#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

edge* new_edge(int dest, int weight){
	edge* e = (edge*)malloc(sizeof(edge)); 
	e->dest= dest; 
	e->weight = weight; 
	e->next = 0; 
	return e; 
}
graph* new_graph(int vertex){
	graph* g = (graph*)malloc(sizeof(graph)); 
	g->vertex = vertex;
	g->neighbors = (edgeList*)malloc(sizeof(edgeList) * vertex); 
	int i = 0; 
	while (i < vertex){
		edgeList* liste = g->neighbors + i++; 
		liste->head = 0; 
		liste->count = 0; 
	} 
	return g; 
}
void addEdge(graph* g, int src, int dest, int weight){
	edgeList* liste = g->neighbors + src; 
	edge* e = new_edge(dest, weight); 
	if (liste->head== 0)
		liste->head = e; 
	else{
		edge* iter = liste->head; 
		while (iter->next )
			iter = iter->next; 
		iter->next = e; 
	}
	liste->count++; 
}
void print_graph(graph* g){
	int i = 0; 
	while (i < g->vertex){
		printf("%d indexli vertexing komsulari : \n-> ", i); 
		edge* iter = g->neighbors[i++].head; 
		while(iter){
			printf("('%d', %d) ", iter->dest, iter->weight); 
			iter = iter->next; 
		}
		puts(""); 
	}
}
list* bfs(graph* g){
	int visited[g->vertex]; 
	int i = 0; 
	while (i < g->vertex)
		visited[i++] = 0; 
	
	list* result = new_list(); 
	list* queue = new_list(); 
	
	push(queue, 0); 
	visited[0] = 1; 
	
	while(queue->count){
		int next_v = shift(queue); 
		push(result, next_v); 
		
		edge* e = g->neighbors[next_v].head; 
		while(e){
			if (!visited[e->dest]){
				push(queue, e->dest); 
				visited[e->dest] = 1;
			}
			e = e->next; 
		}
	}
	free(queue); 
	return result; 
}
void dfs_recursive(graph* g, int v, int visited[], list* result){
	push(result, v); 
	visited[v] = 1; 
	
	edge* e = g->neighbors[v].head; 
	while (e){
		if (!visited[e->dest])
			dfs_recursive(g, e->dest, visited, result); 
		e = e->next; 
	}
}
list* dfs(graph* g){
	int visited[g->vertex]; 
	int i = 0; 
	while (i < g->vertex)
		visited[i++] = 0; 
	
	list* result = new_list(); 
	
	dfs_recursive(g, 0, visited, result); 
	
	return result; 
}
















