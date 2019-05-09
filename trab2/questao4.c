#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "arvoreAVL.h"
#include "vetor.h"

int main(){


    int cont;
    int *vet = criarVetor(1000000);
    int *vetbusca = criarVetor(30);
    preencheVetorTeste(vetbusca,30);
    
    ArvoreBinaria *tree = inicializa();
    avl *arvore = criaAvl();

    int i,x;
    avl *aux;
    ArvoreBinaria *aux2;
    clock_t ticks[2];
    double tempoV = 0, tempoA = 0, timeA = 0, timeB = 0;

    for(i=0;i<10;i++){
        double tempoa, tempob;
        
        tree = inicializa();
        arvore = criaAvl();
        preencheVetor(vet,1000000);

        ticks[0] = clock();


        tree = preencheComVetor(tree,vet,1000000);

        ticks[1] = clock();
        tempoa = (double) (ticks[1] - ticks[0]) * 1000.0/ CLOCKS_PER_SEC;

        printf("%d execucao, criando na arvore binaria em %lf\n", i+1, tempoa);
        //printf("%d",altura(tree));
        ticks[0] = clock();
        for(cont=0;cont<10000;cont++){
        //printf("dando lingua\n");
        arvore = inserirAvl(arvore,vet[cont]);
        }
        ticks[1] = clock();
        tempob = (double) (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d execucao, criando na arvore AVL em %lf\n", i+1, tempob);
    }

    printf("\nA altura da arvore AVL foi : %d\n", arvore->altura);
    printf("\nA altura da arvore binaria foi : %d\n", height(tree));

    for(i=0;i<30;i++){
        ticks[0] = clock();
        aux2 = busca(tree,vetbusca[i]);
        //if(aux2!=NULL) printf("Achou!\n");
        //else printf("Não achou!\n");
        ticks[1] = clock();
        timeA = (double) (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        tempoA += timeA;
        printf("%d° execucao, procurando %d na arvore binaria em: %lf\n\n", i+1, vetbusca[i], timeA);
        ticks[0] = clock();
        aux = buscaAvl(arvore,vetbusca[i]);
        //if(aux!=NULL) printf("Achou!\n");
        //else printf("Não achou!\n");
        ticks[1] = clock();
        timeB = (double) (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        tempoV += timeB;
        printf("%d° execucao, procurando %d na arvore AVL em :%lf\n\n", i+1, vetbusca[i], timeB);
    }

    tempoV /= 30;
    tempoA /= 30;

    printf("tempo gasto em media na arvore binaria foi: %.6lf segundos\n", tempoA);
    printf("tempo gasto em media na arvore AVL foi: %.6lf segundos\n", tempoV);

    return 0;
}
