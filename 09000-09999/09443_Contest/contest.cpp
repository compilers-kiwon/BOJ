#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0x100

int	main(void)
{
	int		n,cnt;
	bool	visited[MAX_SIZE];
	
	cin>>n;
	fill(&visited[(int)'A'],&visited[(int)'Z'+1],false);
	
	for(int i=1;i<=n;i++)
	{
		string	p;
		
		cin>>p;
		visited[(int)p[0]] = true;
	}
	
	cnt = 0;
	
	for(char c='A';c<='Z'&&visited[(int)c]==true;c++)
	{
		cnt++;
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
