#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

typedef	pair<int,int>	T;

int						N,M;
vector<string>			word_set;
map< char,vector<T> >	table;

void	input(void)
{
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
	{
		string	word;
		
		cin>>word;
		
		word_set.push_back(word);
		table[word[0]].push_back(make_pair(i,word.length()));
	}
}

int		main(void)
{
	input();
	
	int	cnt,i;
	
	for(i=1,cnt=0;i<=M;i++)
	{
		string	word;
		
		cin>>word;
		
		for(int j=0;j<table[word[0]].size();j++)
		{
			int& word_index = table[word[0]][j].first;
			int& word_length = table[word[0]][j].second;
			
			if( word_length == word.length() )
			{
				if( word_set[word_index] == word )
				{
					cnt++;
					break;
				}
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
