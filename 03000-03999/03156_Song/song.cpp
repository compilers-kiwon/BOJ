#include	<iostream>
#include	<string>
#include	<map>
#include	<set>

using namespace	std;

typedef	set<string>	Song;

int				N;
map<int,Song>	rank_table;

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int		A,B;
		string	tmp;
		
		cin>>A>>tmp>>B;
		
		for(int j=1;j<=A;j++)
		{
			cin>>tmp;
			rank_table[B].insert(tmp);
		}
	}
}

void	find_rank(void)
{
	set<string>				songs;
	map<int,Song>::iterator	it = rank_table.begin();
	
	for(;it!=rank_table.end();it++)
	{
		int	current_rank = it->first;
		set<string>::iterator s,e;
		
		s = it->second.begin();
		e = it->second.end();
		
		if( songs.size()+1 == current_rank )
		{
			for(;s!=e;s++)
			{
				if( songs.find(*s) == songs.end() )
				{
					cout<<current_rank<<' '<<*s<<'\n';
					songs.insert(*s);
				}
			}
		}
		else
		{
			for(;s!=e;s++)
			{
				songs.insert(*s);
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	find_rank();
	
	return	0;
}
