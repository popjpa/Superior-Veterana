#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
int diamantes[505];
int memo[505][50005];
int t, n;
int dp(int i, int val);
int main()
{
    while(scanf("%d %d", &t, &n)!=EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d", &diamantes[i]);
        for(int i = 0;i <= n;i++)
            for(int j = 0;j <= t;j++)
                memo[i][j] = INF;
        printf("%d\n", dp(0, 0));
    }
    return 0;
}
int dp(int i, int val)
{
    if(val >= t)
        return val;
    if(i == n)
        return INF;
    if(memo[i][val] != INF)
        return memo[i][val];
    return memo[i][val] = min(dp(i+1, val), dp(i+1, diamantes[i] + val));
}
