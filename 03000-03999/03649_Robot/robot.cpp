#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_BLOCKS	(1000000+1)

int	blocks[MAX_NUM_OF_BLOCKS];
int	x,n,l1,l2;

bool	find_two_blocks(void)
{
	int		head,tail;
	bool	result;
	
	for(result=false,head=1,tail=n;head<tail;)
	{
		int	sum;
		
		sum = blocks[head]+blocks[tail];
		
		if( sum > x )
		{
			tail--;
		}
		else if( sum < x )
		{
			head++;
		}
		else
		{
			result = true;
			l1 = blocks[head];
			l2 = blocks[tail];
			
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	while( scanf("%d %d",&x,&n) == 2 )
	{
		for(int i=1;i<=n;i++)
		{
			cin>>blocks[i];
		}
		
		sort(&blocks[1],&blocks[n+1]);
		x *= 10000000;
		
		if( find_two_blocks() == true )
		{
			cout<<"yes "<<l1<<' '<<l2<<'\n';
		}
		else
		{
			cout<<"danger\n";
		}
	}
	
	return	0;
}
