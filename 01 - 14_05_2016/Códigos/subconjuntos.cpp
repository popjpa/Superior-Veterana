#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[] = {1, 2, 3, 4};
    int tam = 4;
    for(int cont=0;cont < (1<<tam);cont++)
    {
        putchar('{');
        for(int i=0;i<tam;i++)
            if(cont & (1<<i))
                printf("%d, ", A[i]);
        puts("}\n");
    }
    return 0;
}
