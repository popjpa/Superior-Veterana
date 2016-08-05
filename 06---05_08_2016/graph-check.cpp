#include <bits/stdc++.h>
#define MAX 100005
#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2
using namespace std;
vector<int>adj[MAX];
int parent[MAX] = {};
char marc[MAX] = {};
int main()
{
	/*
	INSTANCES OF THE PROBLEM
			*/
	return 0;
}
void graphCheck(int v)					//Classification for Tree Edge, because DFS do a Spanning forest or a Spanning of Spanning trees
{
	int u;
	marc[v] = VISITED;
	for(int i = 0;i < adj[v].size();i++)
	{
		u = adj[v][i];
		if(marc[u] == UNVISITED)//tree edge
		{
			parent[u] = v;
			graphCheck(u);
		}
		else if(marc[u] == EXPLORED)	//Can be a Cycle
		{
			if(u == parent[v])			//Bidirecional edge to u and v
				printf(" Two direct path to (%d, %d) and (%d, %d)\n", v, u, u, v);
			else						//Back Edge to an Descendant
				printf(" Back Edge (%d, %d) (Cycle)\n", v, u);
		}
		else if(marc[u] == VISITED)		//A Edge is classified as a Forward Edge if u is a descendant of v.
			printf(" Forward/Cross Edge (%d, %d)\n", v, u);
	}
}
