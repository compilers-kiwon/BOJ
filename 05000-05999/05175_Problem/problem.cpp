#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	char2int(c)	((int)((c)-'0'))

const string	problem_name = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef	vector<int>	Used_Algorithm;

int		str2int(string& str)
{
	int	ret,i;
	
	for(i=ret=0;i<str.length();i++)
	{
		ret = ret*10+char2int(str[i]);
	}
	
	return	ret;
}

void	find_used_algorithm(Used_Algorithm& p,string& str)
{
	string	n;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			p.push_back(str2int(n));
			n.clear();
		}
		else
		{
			n.push_back(str[i]);
		}
	}
}

void	dfs(vector<Used_Algorithm> problem_description,int problem_idx,int* used_cnt,
			int num_of_algorithms,vector<char>& used_problem,vector<char>& answer)
{
	if( problem_idx == problem_description.size() )
	{
		for(int i=1;i<=num_of_algorithms;i++)
		{
			if( used_cnt[i] == 0 )
			{
				return;
			}
		}
		
		if( answer.empty() || used_problem.size() < answer.size() )
		{
			answer = used_problem;
		}
		
		return;
	}
	
	for(int i=0;i<problem_description[problem_idx].size();i++)
	{
		int&	algorithm = problem_description[problem_idx][i];
		
		used_cnt[algorithm]++;
	}
	
	used_problem.push_back(problem_name[problem_idx]);
	dfs(problem_description,problem_idx+1,used_cnt,num_of_algorithms,used_problem,answer);
	used_problem.pop_back();
	
	for(int i=0;i<problem_description[problem_idx].size();i++)
	{
		int&	algorithm = problem_description[problem_idx][i];
		
		used_cnt[algorithm]--;
	}
	
	dfs(problem_description,problem_idx+1,used_cnt,num_of_algorithms,used_problem,answer);
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int i=1;i<=K;i++)
	{
		int						M,N,used_cnt[MAX_SIZE];
		vector<char>			used_problem,answer;
		vector<Used_Algorithm>	problem_description;
		
		cin>>M>>N;getchar();
		
		problem_description.resize(N+1);
		fill(&used_cnt[1],&used_cnt[M+1],0);
		
		for(int j=1;j<=N;j++)
		{
			string	str;
			
			getline(cin,str);
			find_used_algorithm(problem_description[j],str);
		}
		
		dfs(problem_description,1,used_cnt,M,used_problem,answer);
		
		if( i != 1 )
		{
			cout<<'\n';
		}
		cout<<"Data Set "<<i<<":";
		
		for(int j=0;j<answer.size();j++)
		{
			cout<<' '<<answer[j];
		}
		cout<<"\n";
	}
	
	return	0;
}
