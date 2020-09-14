#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SIZE	0x100

typedef	map<string,string>	Website;

int		N,M;
Website	table[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		string	s,p;
		
		cin>>s>>p;
		table[s[0]][s] = p;
	}
	
	for(int i=1;i<=M;i++)
	{
		string	s;
		
		cin>>s;
		cout<<table[s[0]][s]<<'\n';
	}
	
	return	0;
}
