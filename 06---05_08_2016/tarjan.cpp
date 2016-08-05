#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int>adj[MAX];
stack<int>pilha;

int dfs_num[MAX], dfs_low[MAX], visited[MAX];

int tempo, numSCC;

void tarjanSCC(int u);

int main()
{
	int V;
	scanf("%d", &V);
	
	tempo = numSCC = 0;
	memset(dfs_num, 0, sizeof dfs_desc);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(visited, 0, sizeof visited);
	
	for(int i = 1;i <= V;i++)
		if(dfs_num[i] == 0)
			tarjanSCC(i);
			
	return 0;
}
void tarjanSCC(int u)
{
	dfs_num[u] = dfs_low[u] = tempo++;
	pilha.push(u);
	visited[u] = 1;
	
	for(int i = 0;i < adj[u].size();i++)
	{
		int v = adj[v][i];
		if(dfs_num[v] == 0)
			tarjanSCC(v);
			
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u])
	{
		printf("SCC %d:\n", ++numSCC);
		while(1)
		{
			int v = pilha.back();
			pilha.pop();
			visited[v] = 0;
			printf(" %d", v);
			if(u == v)
			{
				printf("\n");
				break;
			}
		}
	}
}
