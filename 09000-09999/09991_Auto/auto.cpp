#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>
#include	<algorithm>

using namespace	std;

int				W,N;
map<string,int>	table;
vector<string>	dictionary;

void	build_dictionary(void)
{
	dictionary.resize(W);
	
	for(int i=0;i<W;i++)
	{
		cin>>dictionary[i];
		table[dictionary[i]] = i+1;
	}
	
	sort(dictionary.begin(),dictionary.end());
}

bool	compare_str(const string& partial,const string& completed)
{
	for(int i=0;i<partial.length();i++)
	{
		if( partial[i] != completed[i] )
		{
			return	false;
		}
	}
	
	return	true;
}

int		find_word(int idx,const string& partial)
{
	vector<string>::iterator	it;
	
	it = lower_bound(dictionary.begin(),dictionary.end(),partial);
	
	if( it == dictionary.end() )
	{
		return	-1;
	}
	
	if( compare_str(partial,*it) == false )
	{
		return	-1;
	}
	
	int	n;
	
	n = it-dictionary.begin()+(idx-1);
	
	if( n >= W )
	{
		return	-1;
	}
	
	if( compare_str(partial,dictionary[n]) == false )
	{
		return	-1;
	}
	
	return	table[dictionary[n]];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>W>>N;
	
	build_dictionary();
	
	for(int i=1;i<=N;i++)
	{
		int		K;
		string	str;
		
		cin>>K>>str;
		cout<<find_word(K,str)<<'\n';
	}
	
	return	0;
}
