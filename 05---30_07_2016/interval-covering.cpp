#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b);
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		vector<pair<int,int> >intervals;
		for(int i = 0;i < n;i++)
		{
			int ini, fim;
			scanf("%d %d", &ini, &fim);
			intervals.push_back(pair<int,int>(ini, fim));
		}
		
		sort(intervals.begin(), intervals.end(), comp);
		
		vector<pair<int,int> >solution;
		int required_min = 0;
		bool current_best_valid = false;
		pair<int,int> current_best;
		bool reach = true;
		
		for(int i = 0;i < n;i++)///Sempre teremos na nossa solução o intervalo mais a esquerda, porém, dos intervalos mais a esquerda, queremos o que são mais a direita
		{
			if(intervals[i].first <= required_min)///Dentro do requerido -> Escolha o mais a direita possível
			{
				if(intervals[i].second > current_best.second)///Escolha o mais a direita possível
				{
					current_best = intervals[i];
					current_best_valid = true;
				}
			}
			else
			{
				if(current_best_valid)///O melhor para o requerido
				{
					solution.push_back(current_best);
					
					required_min = current_best.second; //update o requerido
					current_best_valid = false;
					
					if(required_min >= m)///Chegamos na solução
						break;
				}
				
				if(intervals[i].first <= required_min)//verificação após o update, por estar sendo realizada uma iteração
				{
					if(intervals[i].second > current_best.second)
					{
						current_best = intervals[i];
						current_best_valid = true;
					}
				}
				else///Não existe ninguem com o requerido
				{
					reach = false;
					break;
				}
			}
		}
		if(current_best_valid)///Verifição após a ultima iteração
			solution.push_back(current_best);
			
		if(reach)///existe solução
		{
			printf("%d\n", solution.size());
			for(int i = 0;i < solution.size();i++)
				printf("%d %d\n", solution[i].first, solution[i].second);
		}
		else
			puts("No solution");
	}
	return 0;
}
bool comp(pair<int,int> a, pair<int,int> b)
{
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}
