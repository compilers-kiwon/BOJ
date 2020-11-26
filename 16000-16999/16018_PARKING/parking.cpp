#include	<iostream>
#include	<string>

using namespace	std;

#define	OCCUPIED	'C'

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,cnt;
	string	yesterday,today;
	
	cnt = 0;
	cin>>N>>yesterday>>today;
	
	for(int i=0;i<N;i++)
	{
		if( yesterday[i]==OCCUPIED && today[i]==OCCUPIED )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
