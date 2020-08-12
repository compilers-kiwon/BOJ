#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100000

int	seq[MAX_SIZE],head,tail;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,S,min_len,sum;
	
	min_len = MAX_SIZE;
	cin>>N>>S;
	
	for(int i=1;i<=N;i++)
	{
		cin>>seq[i];
	}
	
	for(head=1,tail=2,sum=seq[1];;)
	{
		if( sum >= S )
		{
			min_len = min(min_len,tail-head);
			
			if( head+1 < tail )
			{
				sum -= seq[head];
				head++;
			}
			else
			{
				if( tail+1 <= N+1 )
				{
					sum += seq[tail];
					tail++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if( tail+1 <= N+1 )
			{
				sum += seq[tail];
				tail++;
			}
			else
			{
				break;
			}
		}
	}
	
	cout<<((min_len==MAX_SIZE)?0:min_len)<<'\n';

	return	0;
}
