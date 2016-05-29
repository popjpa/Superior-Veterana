#include <bits/stdc++.h>
#define MAX 1025
using namespace std;
int grid[MAX][MAX]={};
int x[20001], y[20001];
int main()
{
	int t, d, n, x1, y1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &d, &n);
		for(int i=0;i<n;i++)
			scanf("%d %d %d", &x[i], &y[i], &grid[y[i]][x[i]]);
		for(int x=0;x<MAX;x++)
			for(int y=0;y<MAX;y++)
			{
				x1 = x+d; y1 = y+d;
				if(x1<MAX && y1<MAX)
				{
					
				}
			}
	}
	return 0;
}
