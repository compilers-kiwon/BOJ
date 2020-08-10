#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

bool	compare(string& w1,string& w2)
{
	bool			result;
	
	map<char,char>	table;
	map<char,bool>	visited,used;
	
	result = true;
	
	for(int i=0;i<w1.length();i++)
	{
		char&	c1 = w1[i];
		char&	c2 = w2[i];
		
		if( visited[c1] == false )
		{
			if( used[c2] == false )
			{
				visited[c1] = true;
				used[c2] = true;
				table[c1] = c2;
			}
			else
			{
				result = false;
				break;
			}
		}
		else
		{
			if( table[c1] != c2 )
			{
				result = false;
				break;
			}
		}
	}
	
	return	result;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int	N,cnt;
	
	cin>>N;
	
	vector<string>	words(N+1);
	
	for(int i=1;i<=N;i++)
	{
		cin>>words[i];
	}
	
	cnt = 0;
	
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if( words[i].length()==words[j].length() && compare(words[i],words[j])==true )
			{
				cnt++;
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
