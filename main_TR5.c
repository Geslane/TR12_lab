#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//funcao compara
int compara(void* x, void* y) {
	int xx = *((int*) x);
	int yy = *((int*) y);

	if(xx > yy ){
		return -1;
	}else{
		if(xx < yy ) return 1;
		else return 0;
	}
}

//funcao para imprimir os elementos da heap

void print(void** heap, int fim){
	for (int indice = 0; indice < fim ; indice++) {
		printf("%d - ", *((int*) heap[indice]));
	}
	printf("\n\n");
}

int main() {
	int tam = 10;	int remove = 3;

	HEAP* heap = HEAP_create(tam, compara);
  
	//adicionar elementos
	
	for (int indice = 0; indice < tam; indice++) {
		int * x = malloc(sizeof(int));
		*x = rand() % tam;
		HEAP_add(heap, x);
	}
 
	
	//print elementos
	
  	printf("HEAP INICIAL:\n");
	print(heap->elems, heap->N);

	//removendo elementos iniciais
	
	printf("ELEMENTOS REMOVIDOS:\n");
	for (int i = 0; i < remove; i++) {
		printf("%d - ",*((int*) heap->elems[0]));
		HEAP_remove(heap);

	}
	printf("\n\n");
	
	//heap final
	
	printf("HEAP FINAL:\n");
	print(heap->elems, heap->P);


	return 0;
}

