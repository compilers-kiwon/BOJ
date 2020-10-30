#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		n,cnt;
	string	s1,s2;
	
	cnt = 0;
	cin>>n>>s1>>s2;
	
	for(int i=0;i<n;i++)
	{
		if( s1[i] != s2[i] )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
