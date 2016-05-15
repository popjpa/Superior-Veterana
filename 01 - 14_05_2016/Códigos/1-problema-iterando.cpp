#include <bits/stdc++.h>
using namespace std;
int main()
{
    int abcde, efghi;
    int n;/// efghi / abcde = n
    int used, tmp, cont = 0;
    scanf("%d", &n);
    for(int abcde = 01234;abcde <= (98765/n);abcde++)
    {
        efghi = n * abcde;
        used = (abcde < 10000);
        tmp = abcde;
        while(tmp)
        {
            used |= (1<<(tmp%10));
            tmp /= 10;
        }
        used |= (efghi < 10000);
        tmp = efghi;
        while(tmp)
        {
            used |= (1<<(tmp%10));
            tmp /= 10;
        }
        if(used == ((1<<10)-1))
            printf("%d %d\n", efghi, abcde), cont++;
    }
    printf("%d\n", cont);
    return 0;
}
