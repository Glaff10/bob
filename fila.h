#ifndef FILA_H
#defina FILA_H

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

typedef struct Fila fila;

void criaFila(tipoFila *p);

void insereNaFila(tipoFila *f, tipoDado d);

tipoDado * buscarNaFila(tipoFila f, int chave);

void removeDaFila(tipoFila *f, int chave);

void mostrarFila(tipoFila f);

void destroiFila(tipoFila *f);
