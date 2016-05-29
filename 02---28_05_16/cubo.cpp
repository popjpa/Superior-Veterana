#include <bits/stdc++.h>
using namespace std;
map<string, bool>mapa;
int main()
{
    string s1, s2;
    return 0;
}
void rotate(string s)
{
    if(mapa.find(s)!=mapa.end())
        return;
    mapa[s] = true;
    string neww(6, '0');
    neww[0] = s[0]; neww[2] = s[2]; neww[4] = s[3]; neww[1] = s[4]; neww[5] = s[1]; neww[3] = s[5];
    rotate(neww);
    //....
}

