#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	line;
	int		N,cnt;
	
	cin>>N;
	line.push_back(' ');
	
	for(int i=1;i<=N;i++)
	{
		char	c;
		
		cin>>c;
		line.push_back(c);
	}
	
	cnt = 1;
	
	for(int i=1;i<line.length();i++)
	{
		if( line[i] != line[i-1] )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
