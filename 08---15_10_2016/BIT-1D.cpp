#include <bits/stdc++.h>
#define LSOne(x) (x & -x)
#define MAX 100005
using namespace std;

int bit[MAX], vet[MAX], n;

void update(int k, int val);
int query(int k);

int main()
{
	scanf("%d", &n);
	
	for(int i = 1;i <= n;i++)
		bit[i] = 0;
	
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &vet[i]);
		update(i, vet[i]);
	}
	
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int op;
		scanf("%d", &op);
		if(op == 0)					//Query
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("Query [%d, %d] = %d\n", l, r, query(r) - query(l-1));
		}
		else
		{
			int i, val;
			scanf("%d %d", &i, &val);
			update(i, val);			//Update -> soma ao indice k o valor [val]
		}
	}
	return 0;
}
void update(int k, int val)			//Update -> soma ao indice k o valor [val]
{
	while(k <= n)
	{
		bit[k] += val;
		k += LSOne(k);
	}
}
int query(int k)
{
	int sum = 0;
	while(k)
	{
		sum += bit[k];
		k -= LSOne(k);
	}
	return sum;
}
