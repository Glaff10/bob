#include "stdio.h"
#include "fila.h"

typedef struct{
	int substituivel;
}tipoDado;

typedef struct tipoNo{
	tipoDado info;
	tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *prim;
}tipoFila;

void criaFila(tipoFila *p){
	p->prim = NULL;
}

void insereNaFila(tipoFila *f, tipoDado d) {
  tipoNo *aux;

  aux = (tipoNo *) malloc (sizeof(tipoNo));
  if(!aux) {
    exit(1); // ALGO DEU MUITO ERRADO!
  }
  aux->d = d;
  aux->prox = f->prim;
  f->prim = aux;
}

tipoDado * buscarNaFila(tipoFila f, int chave) {

  while(f.prim != NULL) {
    if(f.prim->substituivel == chave)  {
      return &(f.prim->d);
    }
    f.prim = f.prim->prox;
  }
  return NULL;
}

void removeDaFila(tipoFila *f, int chave) {
	tipoNo *ant,*atual;
	ant = f->prim;

	if(ant) {   // Se hÃ¡ elementos na Fila
    	if(f.prim->substituivel == chave)  {//se quero apagar 1o
      		f->prim =  ant->prox;
      		free(ant);
    	} else { // se nao era o 1o, busca no resto da Fila
      		while(ant->prox != NULL) {   // while(ant->prox) {
				if(f.prim->substituivel == chave)== 0)  {
	  			// entra aqui se achou alguem pra apagar
	  				atual = ant->prox;
	  				ant->prox = atual->prox;
	  				free(atual);
	  				return;
				}
			ant = ant->prox;
      		}
    	}
  	}
}

void mostrarFila(tipoFila f) {
	while(f.prim != NULL) {
		printf("variavel substituivel:%d",f.prim->substituivel);
	f.prim = f.prim->prox;
	}
}

void destroiFila(tipoFila *f) {
	tipoNo *auxPrim,*aux;
	auxPrim = f->prim;
	f->prim = NULL;
  	while(auxPrim) {
    	aux = auxPrim;
    	auxPrim = auxPrim->prox;
    	free(aux);
  	}
}
