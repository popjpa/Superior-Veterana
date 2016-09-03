#include <bits/stdc++.h>
using namespace std;
vector<int>vetor;
int main()
{
    int n, quant = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        int num;
        scanf("%d", &num);
        if(num == 0)
            quant++;
        else
            vetor.push_back(num);
    }
    string num1, num2;
    sort(vetor.begin(), vetor.end());
    int pt = 0;
    if((n%2) == 1)
    {
        num1.push_back(vetor[pt]+'0');
        pt++;
        num2.push_back(vetor[pt]+'0');
        pt++;
        for(int i = 0;i < n && pt < vetor.size();i++)
        {
            if(quant > 0)
            {
                if((i%2) == 0)
                    num1.push_back('0');
                else
                    num2.push_back('0');
                quant--;
            }
            else
            {
                if((i%2) == 0)
                    num1.push_back(vetor[pt] + '0');
                else
                    num2.push_back(vetor[pt] + '0');
                pt++;
            }
        }
    }
    else
    {
        num1.push_back(vetor[pt]+'0');
        pt++;
        num2.push_back(vetor[pt]+'0');
        pt++;
        for(int i = 0;i < n && pt < vetor.size();i++)
        {
            if(quant > 0)
            {
                if((i%2) == 0)
                    num1.push_back('0');
                else
                    num2.push_back('0');
                quant--;
            }
            else
            {
                if((i%2) == 0)
                    num1.push_back(vetor[pt] + '0');
                else
                    num2.push_back(vetor[pt] + '0');
                pt++;
            }
        }
    }
    stringstream ss;
    int n1, n2;
    ss << num1;
    ss >> n1;
    ss.clear();
    ss << num2;
    ss >> n2;
    ss.clear();

    cout<<n1+n2<<endl;
    return 0;
}
