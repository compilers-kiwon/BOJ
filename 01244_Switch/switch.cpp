#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_SWITCH	(100+1)

#define	OFF	0
#define	ON	1

#define	BOY		1
#define	GIRL	2

#define	CHANGE(s)	(((s)+1)%2)

int	main(void)
{
	int	N,state[MAX_NUM_OF_SWITCH],num_of_student;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>state[i];
	}
	
	cin>>num_of_student;
	
	for(int i=1;i<=num_of_student;i++)
	{
		int	s,n;
		
		cin>>s>>n;
		
		if( s == BOY )
		{
			for(int j=n;j<=N;j+=n)
			{
				state[j] = CHANGE(state[j]);
			}
		}
		else
		{
			int	left,right;
			
			state[n] = CHANGE(state[n]);
			
			for(left=n-1,right=n+1;left>=1&&right<=N;left--,right++)
			{
				if( state[left] == state[right] )
				{
					state[left] = state[right] = CHANGE(state[left]);
				}
				else
				{
					break;
				}
			}
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<state[i]<<' ';
		
		if( i%20 == 0 )
		{
			cout<<'\n';
		}
	}
	
	return	0;
}
