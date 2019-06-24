#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"
#include "grafo.h"
#include "string.h"

typedef struct Grafo grafo;

Grafo *cria_grafo(void){
	return NULL;
}

Grafo *preencher_grafo(Grafo *g, int vertices, int arestas){
	
	g = (Grafo*) malloc(sizeof(Grafo));

	srand(time(NULL));
	int valor;

	memset(g->matriz, -1, sizeof(g->matriz)); // setado todos os espaços dessa matriz para -1
	memset(g->visitado, -1, sizeof(g->visitado));

	for(int i=1; i<vertices; i++){
		for(int j=0; j<arestas; j++){
			int valor = rand() % i; // para garantir que é conexo (so pegando vertices anteriores a ele)
			
			if(g->matriz[i][valor]>=0){
				g->matriz[i][valor] = 1;
				g->matriz[valor][i] = 1;
			}	
		}
	}

	return g;

}

void bfs(int v, int tam, Grafo *g){

	queue fila; //TAD de fila
	// no caso aqui seria fila *queue  = criar_fila(queue); algo assim

	fila.push(v); //inserir
	g->visitado[v] = 1; 

	while(!fila.empty()){

		int atual = fila.top(); // topo
		fila.pop(); // retira da fila

		for(int i=0; i<tam; i++){
			if(g->visitado[matriz[v][i]] == -1 && g->matriz[v][i]!=-1){
				fila.push(g->matriz[v][i]);
				g->visitado[g->matriz[v][i]] = 1;
			}
		}
	}
}

void dfs(int v, int tam, Grafo *g){

	for(int i=0; i<tam; i++){

		if(g->visitado[g->matriz[v][i]]==-1 && g->matriz[v][i]!=-1){
			
			int vizinho = g->matriz[v][i];

			g->visitado[g->matriz[v][i]] = 1;
			dfs(vizinho);
		}
	}
}

void dfs_todos_os_caminhos(int v, int tam, Grafo *g){

	for(int i=0; i<tam; i++){

		if(g->visitado[g->matriz[v][i]]==-1 && g->matriz[v][i]!=-1){
			
			int vizinho = g->matriz[v][i];

			g->visitado[g->matriz[v][i]] = 1;
			//acho que tem que printar aqui o caminho, vamo ver
			dfs(vizinho);
			g->visitado[g->matriz[v][i]] = -1;

		}
	}
}
