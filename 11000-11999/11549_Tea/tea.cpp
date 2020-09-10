#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_TEA		4
#define	MAX_NUM_OF_TESTER	5

int	main(void)
{
	int	T,cnt[MAX_NUM_OF_TEA+1];
	
	for(int i=1;i<=MAX_NUM_OF_TEA;i++)
	{
		cnt[i] = 0;
	}
	
	cin>>T;
	
	for(int i=1;i<=MAX_NUM_OF_TESTER;i++)
	{
		int	t;
		
		cin>>t;
		cnt[t]++;
	}
	
	cout<<cnt[T]<<'\n';
	
	return	0;
}
