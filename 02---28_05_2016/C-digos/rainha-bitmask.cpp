#include <bits/stdc++.h>
using namespace std;
int pdig = 0, sdig = 0, row = 0, col = 0;
int linha[8], cont = 0;
void rainha(int c);
int main()
{
    rainha(0);
	printf("cont: %d\n", cont);
    return 0;
}
void rainha(int c)
{
     if(c == 8)
     {///UMA SOLUÇÃO ENCONTRADA
        for(int i=0;i<8;i++)
            printf("(%d, %d), ", linha[i], i);
        putchar('\n');
        cont++;
     }
     else
     {
        for(int r = 0;r < 8;r++)
        {
            if(!(pdig & 1<<(r - c + 7)) && !(sdig & 1<<(r + c)) && !(row & 1<<r) && !(col & 1<<c))
            {///BITMASK PARA ACESSAR DE FORMA RÁPIDA
                pdig |= 1<<(r - c + 7);///setar o bit para 1
                sdig |= 1<<(r + c);
                row |= 1<<r;
                col |= 1<<c;
                linha[c] = r;///guarde o valor para imprimir posteriormente
                rainha(c + 1);
                pdig &= ~(1<<(r - c + 7));///setar o bit para 0
                sdig &= ~(1<<(r + c));
                row &= ~(1<<r);
                col &= ~(1<<c);
            }
        }
     }
}

