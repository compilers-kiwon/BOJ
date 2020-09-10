#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN	(10+1)

int	main(void)
{
	string	line[MAX_LEN];
	int		N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>line[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=line[i].length()-1;j>=0;j--)
		{
			cout<<line[i][j];
		}
		cout<<endl;
	}
	return	0;
}
