#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "vetor.h"

int main(){
	int tamArquivo;
	ArvoreBinaria *arquivo;

	printf("Tamanho do arquivo: \n");
	scanf("%d", &tamArquivo);

	arquivo = recebeArquivo(tamArquivo);
	montarArquivo(arquivo);

	return 1;
}