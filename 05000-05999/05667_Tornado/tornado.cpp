#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	5000

#define	BROKEN		0
#define	FIXED		1

#define	get_left(p,size)	(((p)+(size)-1)%(size))
#define	get_right(p,size)	(((p)+1)%(size))
	
int	main(void)
{
	int	post[MAX_SIZE],N,cnt;

	for(;;)
	{
		if( scanf("%d",&N)!=1 || N==0 )
		{
			break;
		}
		
		queue<int>	fixed;
		
		for(int i=0;i<N;i++)
		{
			scanf("%d",&post[i]);
			
			if( post[i] == FIXED )
			{
				fixed.push(i);
			}
		}
		
		if( fixed.empty() )
		{
			printf("%d\n",(N+1)/2);
			continue;
		}
		
		for(cnt=0;!fixed.empty();)
		{
			int	p,r1,r2;
			
			p = fixed.front();
			fixed.pop();
			
			r1 = get_right(p,N);
			r2 = get_right(r1,N);
			
			if( post[r1]==BROKEN && post[r2]==BROKEN )
			{
				cnt++;
				post[r2] = FIXED;
				fixed.push(r2);
			}
		}
		
		printf("%d\n",cnt);
	}
	
	return	0;
}
