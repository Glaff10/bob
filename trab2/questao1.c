#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "vetor.h"

int main(){
	ArvoreBinaria *tree = inicializa();

	tree = preencheArvore(tree,50);
	printf("Pre-ordem\n");
	preordem(tree);
	printf("Central\n");
	central(tree);
	printf("Pos-ordem\n");
	posordem(tree);
	printf("\n");
	return 1;
}