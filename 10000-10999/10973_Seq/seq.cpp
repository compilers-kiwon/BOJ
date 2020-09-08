#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_NUMBERS	(10000+1)

bool	is_greater(int& a,int& b)
{
	return	a>b;
}

int		main(void)
{
	int	N,i,seq[MAX_NUM_OF_NUMBERS];
		
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>seq[i];
	}
	
	for(i=N;i>=2;i--)
	{
		int&	prev = seq[i-1];
		int&	current = seq[i];
		
		if( current < prev )
		{
			int	min_index = N;
			
			for(int j=i;j<=N;j++)
			{
				if( seq[j] > prev )
				{
					min_index = j-1;
					break;
				}
			}
						
			swap(prev,seq[min_index]);
			sort(&seq[i],&seq[N+1],is_greater);
			
			break;
		}
	}
	
	if( i == 0 )
	{
		cout<<"-1\n";
	}
	else
	{
		for(i=1;i<=N;i++)
		{
			cout<<seq[i]<<' ';
		}
		cout<<endl;
	}
	
	return	0;
}
