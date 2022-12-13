#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP* HEAP_create(int n, COMP* compara){	/*recebe como parametro o tamanho do heap e a funcao campara,retorna um
						ponteiro para uma estrutura heap*/
	HEAP*heap = malloc(sizeof(HEAP));
	heap->N  = n;	//tamanho do vetor
	heap->P = 0;	//numero de elementos no vetor
	heap->elems = malloc(n*(sizeof(void*)));	//o vetor de elementos
	heap->comparador = compara;
	
	return heap;
}

void HEAP_add(HEAP* heap, void* newelem){		/*Adiciona o elemento newelem na heap ordenado se houver espaco, recebe
							como parametro a heap que ira receber o novo elemento e o novo elemento*/
	if ( heap->P < heap->N ){
	
		heap->elems[heap->P] = newelem;	
		int indice = heap->P;
		
		/*o novo elemento vai para a ultima posicao,percorre o braco se for menor que o pai*/
		
		while ( heap->comparador(heap->elems[indice] , heap->elems[(indice - 1) / 2]) == 1) {
		
			void* aux  = heap->elems[indice];
			heap->elems[indice] = heap->elems[(indice - 1) / 2];
			heap->elems[(indice - 1) / 2] = aux ;
			indice = (indice - 1) / 2;
		}
		heap->P++;
	}
}

void* HEAP_remove(HEAP* heap) {		/*remove o menor elemento da heap, recebe como parametro a heap que tera
 						o elemento removido e retorna esse elemento*/
 						
 	/*o primeiro elemento e alterado para a ultima posicao e o ultimo para a primeira*/
 	
	void* menor = heap->elems[0];
	heap->elems[0] = heap->elems[heap->P - 1];
	heap->elems[heap->P - 1] = menor;
	heap->P--;
	
	int pai = 0, filho = pai * 2 + 1;
					
	while (filho < heap->P) {
	
		/* se o filho direito existir e for menor ele realizara a troca*/
		
		if (filho + 1 < heap->P && heap->comparador(heap->elems[filho], heap->elems[filho + 1]) == -1) {
				filho++;
		}
		
		/*se o pai for maior que o filho de menor valor faz a troca*/
		
		if (heap->comparador(heap->elems[pai], heap->elems[filho]) == -1) {
		
			void* guardar = heap->elems[pai];
			heap->elems[pai] = heap->elems[filho];
			heap->elems[filho] = guardar;
			
			pai = filho;
			filho = pai * 2 + 1;
		
		/*se o pai for menor o laco quebra*/
		
		} else {
			break;
		}
	}
	return menor;
}
