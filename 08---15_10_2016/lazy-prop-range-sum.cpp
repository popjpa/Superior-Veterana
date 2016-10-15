#include <bits/stdc++.h>
#define left(x) x<<1			//pai*2
#define right(x) x<<1|1			//(pai*2)+1
#define MAX 100005
using namespace std;

int tree[MAX<<2], lazy[MAX<<2];
int vetor[MAX];

void build(int p, int l, int r);
void updateRange(int p, int l, int r, int ul, int ur, int val);
int query(int p, int l, int r, int ql, int qr);

int main()
{
	int n;
	scanf("%d", &n);			//tamanho do vetor
	
	for(int i = 1;i <= n;i++)
		scanf("%d", &vetor[i]);	//ler o vetor
		
	build(1, 1, n);				//começo sempre pelo nó raiz (sempre indexado na posição 1). E o intervalo de 1 à n.
	
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int opcao;
		scanf("%d", &opcao);
		
		if(opcao == 0)			//Query
		{
			int l, r;
			scanf("%d %d", &l, &r);
			
			printf("Query [%d, %d] = %d\n", query(1, 1, n, l, r));
		}
		else					//Update -> Setar todos os valores de l à r com val
		{
			int l, r, val;
			scanf("%d %d %d", &l, &r, &val);
			
			updateRange(1, 1, n, l, r, val);
		}
	}
	return 0;
}
void build(int p, int l, int r)
{
	lazy[p] = 0;
	if(l == r)					//Nó folha?
	{
		tree[p] = vetor[l];
		pos[l] = p;
	}
	else
	{
		int mid = (l+r)>>1;
		
		build(left(p), l, mid);
		build(right(p), mid+1, r);
		
		tree[p] = tree[left(p)] + tree[right(p)];
	}
}
int query(int p, int l, int r, int ql, int qr)
{
	if(lazy[p] != 0)
	{
		tree[p] = (r-l+1)*lazy[p];
		if(l != r)
		{
			lazy[left(p)] = lazy[p];
			lazy[right(p)] = lazy[p];
		}
		lazy[p] = 0;
	}
	
	if(l > qr || r < ql)		//O intervalo do nó está totalmente fora?
		return 0;
	
	if(l >= ql && r <= qr)		//O intervalo do nó está totalmente dentro?
		return tree[p];
	
	int mid = (l+r)>>1;
	return query(left(p), l, mid, ql, qr) + query(right(p), mid+1, r, ql, qr);
}
void updateRange(int p, int l, int r, int ul, int ur, int val)
{
	if(lazy[p] != 0)
	{
		tree[p] = (r-l+1)*lazy[p];
		if(l != r)
		{
			lazy[left(p)] = lazy[p];
			lazy[right(p)] = lazy[p];
		}
		lazy[p] = 0;
	}
	
	if(l > ur || r < ul)
		return;
	
	if(l >= ul && r <= ur)
	{
		tree[p] = (r-l+1)*val;
		if(l != r)
		{
			lazy[left(p)] = val;
			lazy[right(p)] = val;
		}
		return;
	}
	
	int mid = (l+r)>>1;
	updateRange(left(p), l, mid, ul, ur, val);
	updateRange(right(p), mid+1, r, ul, ur, val);
}
