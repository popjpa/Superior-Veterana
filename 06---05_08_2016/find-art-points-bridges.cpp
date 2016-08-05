#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int>adj[MAX];

int dfs_desc[MAX], dfs_low[MAX], parent[MAX];

int tempo, dfsRoot, rootChildren;

char ArtVert[MAX];//Diz se o vértice é Articulado ou não

void ArtPoint_Bridge(int u);

int main()
{
	int V;
	scanf("%d", &V);
	
	tempo = 0;
	memset(dfs_desc, 0, sizeof dfs_desc);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(ArtVert, false, sizeof ArtVert);
	
	printf("Bridges:\n");
	for(int i = 1;i <= V;i++)
		if(dfs_desc[i] == 0)
		{
			dfsRoot = i;
			rootChildren = 0;
			
			ArtPoint_Bridge(i);
			
			ArtVert[dfsRoot] = (rootChildren > 1); //Caso Especial
		}
		
	printf("Articulation Points:\n");
	for(int i = 1;i <= V;i++)
		if(ArtVert[i])
			printf(" Vertex %d\n", i);
	return 0;
}
void ArtPoint_Bridge(int u)
{
	dfs_desc[u] = dfs_low[u] = tempo++;
	
	for(int i = 0;i < adj[u].size();i++)
	{
		int v = adj[v][i];
		if(dfs_desc[v] == 0)
		{
			parent[v] = u;
			if(u == dfsRoot)
				rootChildren++;
			
			ArtPoint_Bridge(v);
			
			if(dfs_low[v] >= dfs_desc[u])
				ArtVert[u] = true;
			if(dfs_low[v] > dfs_desc[u])
				printf(" Edge (%d, %d) is a bridge\n", u, v);
			
			dfs_low[u] = min(dfs_low[u], dfs_desc[v]);
		}
		else if(v != parent[u])//Is'nt a Bidirecional Edge
			dfs_low[u] = min(dfs_low[u], dfs_desc[v]);
	}
}
