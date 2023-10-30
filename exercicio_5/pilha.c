/*
 * File:   impl_pilha_estatica.c
 * Author: Ednilson Rossi
 *
 * Created on 02 de outubro de 2023
 */


#include "pilha.h"


struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};


void init(Pilha* pilha){

	*pilha = malloc(sizeof(struct stack));

	if(*pilha != NULL){
		(*pilha)->topo = -1;
	}
}


bool is_full(Pilha pilha){
	
	if(pilha->topo == MAX_STACK_SIZE - 1){
		return true;
    }else{
	    return false;
    }
}

bool is_empty(Pilha pilha){
	
    return pilha->topo == -1 ? true : false;

}


bool push(Pilha pilha, Tipo_Informacao elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_full(pilha) ){
            pilha->topo += 1;
            pilha->itens[pilha->topo] = elemento;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_empty(pilha) ){
			*elemento = pilha->itens[pilha->topo];
			pilha->topo -= 1;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool to_equals(Pilha pilha1, Pilha pilha2) {
    if (pilha1->topo != pilha2->topo) {
        return false; 
    }

    for (int i = 0; i <= pilha1->topo; i++) {
        if (pilha1->itens[i] != pilha2->itens[i]) {
            return false; 
        }
    }

    return true; 
}
