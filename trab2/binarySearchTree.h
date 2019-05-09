#include<stdlib.h>
#include<stdio.h>

struct bst{
  int num;
  struct bst* esq;
  struct bst* dir;
};

typedef struct bst bst;

bst* criaArvore();

bst* insereArvore(bst *a, int num);

bst* busca(bst *a, int num);

void imprimeArvore(bst *a,int v);

bst* libera(bst *a);

int alturaBST(bst *atu);

int numElementosBST(bst *atu);

int taEmOrdemBST(bst *atu);
