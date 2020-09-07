#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

void	reverse_str(string& src,string& dst)
{
	for(int i=src.length()-1;i>=0;i--)
	{
		dst.push_back(src[i]);
	}
}

int		main(void)
{
	int		N;
	bool	found;
	
	cin>>N;
	
	vector<string>	words(N+1);
	
	for(int i=1;i<=N;i++)
	{
		cin>>words[i];
	}
	
	if( N == 1 )
	{
		cout<<words[1].length()<<' '<<words[1][words[1].length()/2]<<endl;
		return	0;
	}
	
	found = false;
	
	for(int i=1;found==false && i<=N-1;i++)
	{
		for(int j=i+1;found==false && j<=N;j++)
		{
			if( words[i].length() == words[j].length() )
			{
				string	reverse;
				
				reverse_str(words[j],reverse);
				
				if( words[i] == reverse )
				{
					cout<<words[i].length()<<' '<<words[i][words[i].length()/2]<<endl;
					found = true;
				}
			}
		}
	}
	
	if( found == false )
	{
		cout<<words[1].length()<<' '<<words[1][words[1].length()/2]<<endl;
	}
	
	return	0;
}
