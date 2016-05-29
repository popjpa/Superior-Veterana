#include <iostream>
#include <bitset>
#include <stdio.h>
using namespace std;
bitset<16>pdig, sdig, row, col;
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
            if(!pdig.test(r - c + 7) && !sdig.test(r + c) && !row.test(r) && !col.test(c)) 
            {///BITMASK PARA ACESSAR DE FORMA RÁPIDA
                pdig.set(r - c + 7);
                sdig.set(r + c);
                row.set(r);
                col.set(c);
                linha[c] = r;
                rainha(c + 1);
                pdig.reset(r - c + 7);
                sdig.reset(r + c);
                row.reset(r);
                col.reset(c);
            }
        }
     }
}
