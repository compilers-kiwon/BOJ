#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_NUM	10000

bool	table[MAX_NUM+1];

int		main(void)
{
	for(int i=1,to=sqrt(MAX_NUM);i<=to;i++)
	{
		table[i*i] = true;
	}
	
	int	min_value,sum;
	int	M,N;
	
	cin>>M>>N;
	
	for(min_value=MAX_NUM+1,sum=0;M<=N;++M)
	{
		if( table[M] == true )
		{
			min_value = min(min_value,M);
			sum += M;
		}
	}
	
	if( min_value == MAX_NUM+1 )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<sum<<endl<<min_value<<endl;
	}
	return	0;
}
