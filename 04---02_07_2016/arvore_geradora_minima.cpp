#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int pai[MAX], peso[MAX];
struct ARESTA
{
	int v1, v2;
	int peso_ar;
	ARESTA(int a, int b, int c)
	{
		v1 = a; v2 = b; peso_ar = c;
	}
};
ARESTA arestas[MAX];
struct comp
{
	bool operator()(ARESTA a1, ARESTA a2)
	{
		return a1.peso_ar > a2.peso_ar;
	}
};
int main()
{
	//n é a quantidade de vertices
	//m é a quantidade de arestas
	
	priority_queue<ARESTA, vector<ARESTA>, comp>fila;
	int n, m;
	int v1, v2, p;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		pai[i] = i;
		peso[i] = 1;
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d", &v1, &v2, &p);
		fila.push(ARESTA(v1, v2, p));
	}
	int q = n - 1;
	int soma_minima = 0;
	while(q && !fila.empty())
	{
		v1 = fila.top().v1;
		v2 = fila.top().v2;
		p = fila.top().peso_ar;
		fila.pop();
		if(ffind(v1) != ffind(v2))
		{
			join(v1, v2);
			soma_minima += p;
			q--;
		}
	}
	printf("A melhor solucao para a Arvore Geradora Minima seria %d\n", soma_minima);
	return 0;
}
void join(int v1, int v2)
{
	if(ffind(v1) == ffind(v2))
		return;
	if(peso[v1] < peso[v2])
	{
		pai[v1] = v2;
		peso[v2] += peso[v1];
	}
	else
	{
		pai[v2] = v1;
		peso[v1] += peso[v2];
	}
}
int ffind(int x)
{
	if(pai[x] == x)
		return x;
	else
		return pai[x] = ffind(pai[x]);
}
