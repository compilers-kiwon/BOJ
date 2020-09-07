#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	IN_RANGE_LEFT(head,tail,x)	((head)<=(x)&&(x)<(tail))
#define	IN_RANGE_RIGHT(head,tail,x)	((head)<(x)&&(x)<=(tail))

typedef	struct	_BRIDGE_INFO	Bridge;
struct	_BRIDGE_INFO
{
	int	y,x1,x2;
};

int	main(void)
{
	int		N,total;
	Bridge	b[MAX_SIZE];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>b[i].y>>b[i].x1>>b[i].x2;
	}
	
	total = 0;
	
	for(int i=1;i<=N;i++)
	{
		int&	left = b[i].x1;
		int&	right = b[i].x2;
		int		left_height,right_height;
		
		left_height = right_height = b[i].y;
		
		for(int j=1;j<=N;j++)
		{
			if( i==j || b[j].y>=b[i].y )
			{
				continue;
			}
			
			int&	head = b[j].x1;
			int&	tail = b[j].x2;
			
			if( IN_RANGE_LEFT(head,tail,left) )
			{
				left_height = min(left_height,b[i].y-b[j].y);
			}
			
			if( IN_RANGE_RIGHT(head,tail,right) )
			{
				right_height = min(right_height,b[i].y-b[j].y);
			}
		}
		
		total += left_height+right_height;
	}
	
	cout<<total<<'\n';
	
	return	0;
}
