#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string r;
    getline(cin, s);
    getline(cin, r);
    int pos;
    do
    {
        pos = s.find(r);
        if(pos == -1)
            break;
        s.erase(pos, r.size()+1);
        //cout<<s<<endl;
    }while(1);
    stringstream ss;
    ss << s;
    //cout<<endl;
    int cont = 0;
    while(ss >> s)
    {
        if(cont)
            cout<<" ";
        cout<<s;
        cont = 1;
    }
    if(cont == 0)
        cout<<"$";
    cout<<"\n";
    return 0;
}
