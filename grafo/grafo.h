#ifndef GRAFO_H
#define GRAFO_H

#define MAX 10

struct Grafo{
	
	int matriz[MAX][MAX];
	int visitado[MAX];
};
typedef struct Grafo grafo;

//funcoes

Grafo *cria_grafo(void)
Grafo *preencher_grafo(Grafo *g, int vertices, int arestas);
void bfs(int v, int tam, Grafo *g);
void dfs(int v, int tam, Grafo *g);
void dfs_todos_os_caminhos(int v, int tam, Grafo *g);
