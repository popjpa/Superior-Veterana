#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int pai[MAX], peso[MAX];
int main()
{
	//n é a quantidade de vertices
	//m é a quantidade de arestas
	int n, m;
	int v1, v2;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		pai[i] = i;
		peso[i] = 1;
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &v1, &v2);
		join(v1, v2);
	}
	int q;//quantidade de consultas
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d", &v1, &v2);
		if(ffind(v1) == ffind(v2))
			puts("Yes");
		else
			puts("No");
	}
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
