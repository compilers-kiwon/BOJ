#include	<iostream>
#include	<queue>

using namespace	std;

#define	NUM_OF_STONE	100

typedef	pair<int,int>	Sec;	// first:location, second:offset

#define	BLUE		0
#define	RED			1
#define	GREEN		2
#define	MAX_COLOR	3

#define	NEXT_COLOR(C)	(((C)+1)%MAX_COLOR)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

int		stone[NUM_OF_STONE];

void	print(int n)
{
	printf("%d",n/100);
	printf(".%02d\n",n%100);
}

void	bfs(int num_of_secretary)
{
	queue<Sec>	sq;
	
	for(int i=1;i<=num_of_secretary;i++)
	{
		int		sn;
		char	d;
		
		cin>>sn>>d;
		
		if( d == 'R' )
		{
			sq.push(make_pair(sn,1));
		}
		else
		{
			sq.push(make_pair(sn,-1));
		}
	}
	
	while( sq.size() != 0 )
	{
		for(int i=1,to=sq.size();i<=to;i++)
		{
			Sec	next;
			
			next = sq.front();
			sq.pop();
			
			next.first += next.second;
			
			if( IN_RANGE(1,next.first,NUM_OF_STONE) )
			{
				stone[next.first] = NEXT_COLOR(stone[next.first]);
				sq.push(next);
			}
		}
	}
}

int		main(void)
{
	int	P,N,a,b,c;
	
	cin>>P>>N;
	
	bfs(N);
	
	a = b = c = 0;
	
	for(int i=1;i<=NUM_OF_STONE;i++)
	{
		switch(stone[i])
		{
			case	BLUE:
				a++;
				break;
			case	RED:
				b++;
				break;
			case	GREEN:
				c++;
				break;
			default:
				// do nothing
				break;
		}
	}
	
	print(a*P);
	print(b*P);
	print(c*P);
	
	return	0;
}
