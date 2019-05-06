#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "vetor.h"

int main(){
	int *vet = criarVetor(1000000), *teste = criarVetor(30);
	ArvoreBinaria *tree = inicializa(), *aux;
	char op[10];
	int cont, valor;
	clock_t ticks[2];
	double tempoVet, tempoArv, mediaVet, mediaArv;

	preencheVetor(vet,10000);
	preencheVetorTeste(teste,30);
	tree = preencheComVetor(tree,vet,10000);
	mediaVet = 0.0;
	mediaArv = 0.0;

	for(cont=0;cont<30;cont++){
		valor = teste[cont];
		printf("Valor da busca %d\n", valor);
		printf("Resultado da busca no vetor:\n");
		ticks[0] = clock();
		if(!buscaBinariaVetor(vet,valor,1000000)) printf("Achou!\n");
		else printf("Não achou!\n");
		ticks[1] = clock();
		tempoVet = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

		printf("Resultado da busca na arvore\n");
		ticks[0] = clock();
		aux = busca(tree,valor);
		if(aux!=NULL) printf("Achou!\n");
		else printf("Não achou!\n");
		ticks[1] = clock();
		tempoArv = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;		

		mediaVet = mediaVet + tempoVet;
		mediaArv = mediaArv + tempoArv;
		printf("Tempo de busca no vetor: %g ms.\n", tempoVet);
		printf("Tempo de busca na arvore: %g ms.\n", tempoArv);
	}

	mediaVet = mediaVet/30.0;
	mediaArv = mediaArv/30.0;
	printf("\n\n");
	printf("Tempo medio vetor: %g ms.\n", mediaVet);
	printf("Tempo medio arvore: %g ms.\n", mediaArv);
	scanf("%s", op);
	return 1;
}