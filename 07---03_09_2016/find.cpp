#include <bits/stdc++.h>
using namespace std;
int main()
{
    string grandona;
    string pequena;
    getline(cin, grandona);
    getline(cin, pequena);
    int pos = -1;
    vector<int>vet;
    do
    {
        pos = grandona.find(pequena, pos+1);
        if(pos == -1)
            break;
        else
        {
            vet.push_back(pos);
        }
    }while(1);
    for(int i = 0;i < vet.size();i++)
        cout<<vet[i]<<" ";
    cout<<endl;
    return 0;
}


