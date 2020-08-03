#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	MAX_NUMBER	1000

typedef	vector<int>	Candidate;

int					N,number[MAX_SIZE];
vector<int>			odd,even,prime_pair[MAX_SIZE];
vector<bool>		prime_table(MAX_NUMBER+MAX_NUMBER+1,true);

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>number[i];
		
		if( number[i]%2 == 1 )
		{
			odd.push_back(i);
		}
		else
		{
			even.push_back(i);
		}
	}
	
	for(int i=2;i<=MAX_NUMBER*2;i++)
	{
		if( prime_table[i] == true )
		{
			for(int j=i+i;j<=MAX_NUMBER*2;j+=i)
			{
				prime_table[j] = false;
			}
		}
	}
	
	for(int i=0;i<odd.size();i++)
	{
		for(int j=0;j<even.size();j++)
		{
			int&	odd_n = number[odd[i]];
			int&	even_n = number[even[j]];
			
			if( prime_table[odd_n+even_n] == true )
			{
				prime_pair[odd[i]].push_back(even[j]);
				prime_pair[even[j]].push_back(odd[i]);
			}
		}
	}
}

bool	dfs(vector<int>& matched_number,vector<bool>& visited,int nIndex)
{
	if( visited[nIndex] == true )
	{
		return	false;
	}
	
	visited[nIndex] = true;
	
	vector<int>& my_candidates = prime_pair[nIndex];

	for(int i=0;i<my_candidates.size();i++)
	{
		int&	candidate = my_candidates[i];
		
		if( matched_number[candidate]==0 || dfs(matched_number,visited,matched_number[candidate]) )
		{
			matched_number[candidate] = nIndex;
			return	true;
		}
	}
	
	return	false;
}

void	find_pair(vector<int>& v1,vector<int>& v2)
{
	vector<int>		answer;
	vector<int>&	candidate_of_min_number = prime_pair[v1[0]];
	
	for(int i=0;i<candidate_of_min_number.size();i++)
	{
		int		cnt;		
		int&	candidate = candidate_of_min_number[i];
		
		vector<int>	matched_number(N+1,0);
		
		matched_number[candidate] = v1[0];
		cnt = 1;
		
		for(int j=1;j<v1.size();j++)
		{
			vector<bool>	visited(v1.size(),false);
			
			visited[v1[0]] = true;
			
			if( dfs(matched_number,visited,v1[j]) == true )
			{
				cnt++;
			}
		}
		
		if( cnt == v1.size() )
		{
			answer.push_back(number[candidate]);
		}
	}
	
	if( answer.size() == 0 )
	{
		cout<<"-1\n";
	}
	else
	{
		sort(answer.begin(),answer.end());
		
		for(int i=0;i<answer.size();i++)
		{
			cout<<answer[i]<<' ';
		}
		cout<<'\n';	
	}
}

int		main(void)
{
	init();

	if( even.size() != odd.size() )
	{
		cout<<"-1\n";
		return	0;
	}
	
	if( number[1]%2 == 0 )
	{
		find_pair(even,odd);
	}
	else
	{
		find_pair(odd,even);
	}
	
	return	0;
}
