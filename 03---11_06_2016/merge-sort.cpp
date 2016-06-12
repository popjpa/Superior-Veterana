#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int B[MAX];
void merge(int A[], int p, int r);
void combine(int A[], int p, int q, int r);
int main()
{
	int AA[MAX];
	int n;
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
		scanf("%d", &AA[i]);
		
	merge(AA, 0, n-1);
	
	for(int i=0;i<n;i++)
		printf("%d ", AA[i]);
	putchar('\n');
	
	return 0;
}
void merge(int A[], int p, int r)
{
	if(p < r)
	{
		int q = (p+r)>>1;
		merge(A, p, q);
		merge(A, q+1, r);
		combine(A, p, q, r);
	}
}
void combine(int A[], int p, int q, int r)
{
	int i, j, k;
	for(i = p;i <= q;i++)
		B[i] = A[i];
	for(j = q+1;j <= r;j++)
		B[r+q+1-j] = A[j];
	i = p;
	j = r;
	for(k = p;k <= r;k++)
		if(B[i] <= B[j])
		{
			A[k] = B[i];
			i++;
		}
		else
		{
			A[k] = B[j];
			j--;
		}
}
