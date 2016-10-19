#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int grid[MAX][MAX];
int tree[1000005];

int build(int p, int x1, int y1, int x2, int y2);
int update(int p, int x1, int y1, int x2, int y2, int x, int y, int val);
int query(int p, int x1, int y1, int x2, int y2, int qx1, int qy1, int qx2, int qy2);

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			scanf("%d", &grid[i][j]);
	
	build(1, 1, 1, n, m);
	
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int op;
		scanf("%d", &op);
		if(op == 0)
		{
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("Query [%d, %d][%d, %d] = %d\n", x1, y1, x2, y2, query(1, 1, 1, n, m, x1, y1, x2, y2));
		}
		else
		{
			int x, y, val;
			scanf("%d %d %d", &x, &y, &val);
			update(1, 1, 1, n, m, x, y, val);
		}
	}
	return 0;
}
int build(int p, int x1, int y1, int x2, int y2)
{
	if(x1 > x2 || y1 > y2)
		return 0;
	
	if(x1 == x2 && y1 == y2)
		return tree[p] = grid[x1][y1];
	
	int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;		
	return tree[p] =  build(child-2, x1, y1, midx, midy)		//Dividir em quatro partes
					+ build(child-1, x1, midy+1, midx, y2)
					+ build(child, midx+1, y1, x2, midy)		//problema -> algum filho pode nao existir (matrix nao quadrada)
					+ build(child+1, midx+1, midy+1, x2, y2);						
}
int query(int p, int x1, int y1, int x2, int y2, int qx1, int qy1, int qx2, int qy2)
{
	if(x1 > qx2 || y1 > qy2 || x2 < qx1 || y2 < qy1 || x1 > x2 || y1 > y2)
		return 0;
	
	if(x1 >= qx1 && y1 >= qy1 && x2 <= qx2 && y2 <= qy2)
		return tree[p];
	
	int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;
	return 	query(child-2, x1, y1, midx, midy, qx1, qy1, qx2, qy2)
		+	query(child-1, x1, midy+1, midx, y2, qx1, qy1, qx2, qy2)
		+	query(child, midx+1, y1, x2, midy, qx1, qy1, qx2, qy2)
		+	query(child+1, midx+1, midy+1, x2, y2, qx1, qy1, qx2, qy2);
}
int update(int p, int x1, int y1, int x2, int y2, int x, int y, int val)
{
	if(x1 > x2 || y1 > y2)
		return 0;
	
	if (x1 > x || y1 > y || x2 < x || y2 < y)
		return tree[p];
	
	if(x == x1 && y == y1 && x == x2 && y == y2)
		return tree[p] = val;
	
	int midx = (x1+x2)>>1, midy = (y1+y2)>>1, child = p<<2;
	return tree[p] =  update(child-2, x1, y1, midx, midy, x, y, val)
					+ update(child-1, x1, midy+1, midx, y2, x, y, val)
					+ update(child, midx+1, y1, x2, midy, x, y, val) 
					+ update(child+1, midx+1, midy+1, x2, y2, x, y, val);
}
