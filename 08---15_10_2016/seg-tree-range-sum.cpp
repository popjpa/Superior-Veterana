#include <bits/stdc++.h>
#define left(x) x<<1	//pai*2
#define right(x) x<<1|1	//(pai*2)+1
#define MAX 100005
using namespace std;

int tree[MAX<<2];
int vetor[MAX], pos[MAX];		//pos -> posições das indexações dos elementos do vetor na seg tree

void build(int p, int l, int r);
void update(int i, int val);
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
		else					//Update
		{
			int i, val;
			scanf("%d %d", &i, &val);
			
			update(i, val);
		}
	}
	return 0;
}
void build(int p, int l, int r)
{
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
	if(l > qr || r < ql)		//O intervalo do nó está totalmente fora?
		return 0;
	
	if(l >= ql && r <= qr)		//O intervalo do nó está totalmente dentro?
		return tree[p];
	
	int mid = (l+r)>>1;
	return query(left(p), l, mid, ql, qr) + query(right(p), mid+1, r, ql, qr);
}
void update(int i, int val)
{
	int p = pos[i];
	tree[p] = val;				//Pega a posição em que i está indexado
	
	while(p>>=1)				//Subir a árvore
		tree[p] = tree[left(p)] + tree[right(p)];
}
