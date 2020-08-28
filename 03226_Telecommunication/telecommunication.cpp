#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_TIME			(24*60)
#define	GET_TIME_INDEX(H,M)	(((H)*60+(M))%MAX_TIME)
#define	char2int(c)			((int)((c)-'0'))
	
int	N,cost[MAX_TIME];

int	main(void)
{
	for(int i=0;i<MAX_TIME;i++)
	{
		cost[i] = 5;
	}
	
	for(int i=GET_TIME_INDEX(7,00);i<GET_TIME_INDEX(19,00);i++)
	{
		cost[i] = 10;
	}
	
	int	N,total_cost;
	
	cin>>N;
	total_cost = 0;
	
	while(N>0)
	{
		string	from;
		int		time,sh,sm;
		
		cin>>from>>time;
		
		sh = char2int(from[0])*10+char2int(from[1]);
		sm = char2int(from[3])*10+char2int(from[4]);
		
		for(int start_time_index=GET_TIME_INDEX(sh,sm),i=0;i<time;i++)
		{
			total_cost += cost[(start_time_index+i)%MAX_TIME];
		}
		
		N--;
	}
	cout<<total_cost<<endl;
	
	return	0;
}
