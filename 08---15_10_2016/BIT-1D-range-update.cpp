#include <bits/stdc++.h>
#define LSOne(x) (x & -x)
#define MAX 100005
using namespace std;

int bit1[MAX], bit2[MAX], n;

void update(int bit[], int k, int val);
void updateRange(int l, int r, int val);
int query(int bit[], int k);
int queryRange(int k);

int main()
{
	scanf("%d", &n);
	
	for(int i = 1;i <= n;i++)
		bit1[i] = bit2[i] = 0;
	
	int num;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &num);
		updateRange(i, i, num);
	}
	
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int op;
		scanf("%d", &op);
		if(op == 0)							//Query
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("Query [%d, %d] = %d\n", l, r, queryRange(r) - queryRange(l-1));
		}
		else
		{
			int l, r, val;
			scanf("%d %d %d", &l, &r, &val);
			updateRange(l, r, val);			//Update -> soma ao indice k o valor [val]
		}
	}
	return 0;
}
void updateRange(int l, int r, int val)
{
	update(bit1, l, val);
	update(bit1, r+1, -val);
	update(bit2, l, val*(l-1));
	update(bit2, r+1, -val*r);
}
void update(int bit[], int k, int val)
{
	while(k <= n)
	{
		bit[k] += val;
		k += LSOne(k);
	}
}
int queryRange(int k)
{
	return (query(bit1, k) * k) - query(bit2, k);
}
int query(int bit[], int k)
{
	int sum = 0;
	while(k)
	{
		sum += bit[k];
		k -= LSOne(k);
	}
	return sum;
}
