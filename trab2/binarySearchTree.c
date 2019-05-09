#include "binarySearchTree.h"

bst* criaArvore(){
  bst *a;
  a = NULL;
  return a;
}

bst* insereArvore(bst *a, int num){
  if(a == NULL){
    a = (bst*)malloc(sizeof(bst));
    a->num = num;
    a->esq = a->dir = NULL;
  }
  else if(num < a->num){
    a->esq = insereArvore(a->esq,num);
  }
  else{
    a->dir = insereArvore(a->dir,num);
  }
  return a;
}

bst* busca(bst *a, int num){
  bst *ret = NULL;
  if(a == NULL){
    ret = NULL;
  }
  else if(num > a->num){
    ret = busca(a->dir,num);
  }
  else if(num < a->num){
    ret = busca(a->esq,num);
  }
  else{
    ret = a;
  }
  return ret;
}

void imprimeArvore(bst *a,int v){
  if(a != NULL){
    if(v==0)printf("%d\n",a->num);
    imprimeArvore(a->esq,v);
    if(v==1)printf("%d\n",a->num);
    imprimeArvore(a->dir,v);
    if(v==2)printf("%d\n",a->num);
  }
}

bst* libera(bst *a){
  if(a != NULL){
    libera(a->esq);
    libera(a->dir);
    free(a);
  }
  return NULL;
}

int max2(int a, int b){
  if(a>b) return a;
  return b;
}
int alturaBST(bst *atu){
  if(atu) return 1 + max2(alturaBST(atu->dir), alturaBST(atu->esq));
  return 0;
}


int numElementosBST(bst *atu){
    int res = 0;
    if(atu) res = 1 + numElementosBST(atu->esq) + numElementosBST(atu->dir);
    return res;
}

int taEmOrdemBST(bst *atu){
    int res = 1;
    if(atu->esq) res &= (taEmOrdemBST(atu->esq) && atu->esq->num <= atu->num);
    if(atu->dir) res &= (taEmOrdemBST(atu->dir) && atu->dir->num >= atu->num);
    return res;
}
