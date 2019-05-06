#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "arvoreAVL.h"
#include "vetor.h"

int main(){


    int *vet = criarVetor(1000000);
    ArvoreBinaria *tree = inicializa();
    ArvoreAVL *arvore = 
    preencheVetor(vet,1000000);
    tree = preencheComVetor(tree,vet,1000000);


    *prim = Cria_Arvore_Binaria();
    *primo = Cria_Arvore_AVL();

    preenche_Arvore_Binaria(1000000, prim);

    preenche_Arvore_AVL(1000000, primo);

    int i,x;
    clock_t in, f;
    double tempob, tempoi, tempoq;
    Arvore_binaria first[10];
    Arvore_AVL sec[10];

    for(i=0;i<10;i++){
        double tempoa, tempob;
        in = clock();

        Cria_Arvore_Binaria();
        preenche_Arvore_Binaria(1000000, prim);

        f = clock();

        tempoa += ((double) (f-in))/CLOCKS_PER_SEC

        in = clock();

        Cria_Arvore_AVL();
        preenche_Arvore_AVL(1000000, prim);

        f = clock();

        tempob += ((double) (f-in))/CLOCKS_PER_SEC

        printf("%d° execucao, criando no arvore binaria em %lf", i, tempoa);
        printf("%d° execucao, criando na arvore AVL em %lf", i, tempob);
    }

     for(i=0;i<30;i++){
        in = clock();

        x = 1000000/(i+1);
        int t = busca_binaria_Arvore_Binaria(x, prim);

        f = clock();

        tempoV += ((double) (f-in))/CLOCKS_PER_SEC

        in = clock();

        tempoV += ((double) (f-in))/CLOCKS_PER_SEC

        int h = busca_Arvore_AVL(x, primo);

        f = clock();

        tempoA += ((double) (f-in))/CLOCKS_PER_SEC

        printf("%d° execucao, procurando %d na arvore binaria e achando %d em %lf", i, x, t, tempoV);
        printf("%d° execucao, procurando %d na arvore AVL e achando %d em %lf", i, x, h, tempoA);
    }

    tempoV /= 30;
    tempoA /= 30;

    printf("tempo gasto em media no vetor foi: %.1lf segundos\n", tempoV);
    printf("tempo gasto em media na arvore foi: %.1lf segundos\n", tempoA);

    return 1;
}