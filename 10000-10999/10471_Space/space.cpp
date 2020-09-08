#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

int		W,P;
bool	space[MAX_SIZE];
int		partition_index[MAX_SIZE];

int		main(void)
{
	cin>>W>>P;
	
	space[W] = true;
	
	for(int i=1;i<=P;i++)
	{
		int&	L = partition_index[i];
		
		cin>>L;
		space[L] = space[W-L] = true;
		
		for(int j=1;j<i;j++)
		{
			space[L-partition_index[j]] = true;
		}
	}
	
	for(int i=1;i<=W;i++)
	{
		if( space[i] == true )
		{
			cout<<i<<' ';
		}
	}
	cout<<'\n';
	
	return	0;
}
