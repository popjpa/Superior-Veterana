#include <bits/stdc++.h>
#define LSOne(x) (x & -x)
#define MAX 1030
using namespace std;
int bit[MAX][MAX], ft[MAX][MAX], n;
void update(int x, int y, int v);
int prersq_2d(int x1, int y1, int x2, int y2);
int query(int x, int y);
int main()
{
	memset(bit, 0, sizeof(bit));
	memset(ft, 0, sizeof(ft));
    scanf("%d", &n);
    int q;
    scanf("%d", &q);
    while(q--)
    {
    	int op;
    	scanf("%d", &op);
        if(op == 0)				//Update -> setar num em (x, y)
        {
        	int x, y, num;
            scanf("%d %d %d", &x, &y, &num);
            update(x, y, num - ft[x][y]);
            ft[x][y] = num;
        }
        else					//Query Sum
        {
        	int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("Query [%d, %d] -> [%d, %d] = %d\n", prersq_2d(x1, y1, x2, y2));
        }
    }
    return 0;
}
void update(int x, int y, int v)
{
    int y1;
    while(x <= n)
    {
        y1 = y;
        while(y1 <= n)
        {
            bit[x][y1] += v;
            y1 += LSOne(y1);
        }
        x += LSOne(x);
    }
}
int prersq_2d(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) + query(x1-1, y1-1) - query(x1-1, y2) - query(x2, y1-1);
}
int query(int x, int y)
{
    int sum = 0, y1;
    while(x)
    {
        y1 = y;
        while(y1)
        {
            sum += bit[x][y1];
            y1 -= LSOne(y1);
        }
        x -= LSOne(x);
    }
    return sum;
}
