#include	<iostream>
#include	<string>
#include	<vector>
#include	<set>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

int	check_genome(int g_index,vector<string>& spotty,vector<string>& plain)
{
	set<char>	spotty_genome;
	
	for(int i=0;i<spotty.size();i++)
	{
		string&	genome = spotty[i];
		
		spotty_genome.insert(genome[g_index]);
	}
	
	if( spotty_genome.size() == 0 )
	{
		return	TRUE;
	}
	
	if( spotty_genome.size() == 4 )
	{
		return	FALSE;
	}
	
	int	result;
	
	result = TRUE;
	
	for(int i=0;i<plain.size();i++)
	{
		string&	genome = plain[i];
		
		if( spotty_genome.find(genome[g_index]) != spotty_genome.end() )
		{
			result = FALSE;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	int				N,M;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	vector<string>	s(N),p(N);
	
	for(int i=0;i<N;i++)
	{
		cin>>s[i];
	}
	
	for(int i=0;i<N;i++)
	{
		cin>>p[i];
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=0;i<M;i++)
	{
		cnt += check_genome(i,s,p);
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
