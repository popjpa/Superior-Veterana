#include <bits/stdc++.h>
using namespace std;
bool compara(char a, char b)
{
    return a > b;
}
int main()
{
    string num, copia, copia2;
    cin>>num;
    copia = num;
    copia2 = num;
    sort(copia2.begin(), copia2.end(), compara);
    if(num == copia2)
    {
        cout<<"BIGGEST\n";
        return 0;
    }
    do
    {
        if(copia > num)
        {
            cout<<copia<<endl;
            break;
        }
    }while(next_permutation(copia.begin(), copia.end()));
    return 0;
}

