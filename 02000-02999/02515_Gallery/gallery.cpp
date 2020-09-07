#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_PICTURE	(300000+1)

typedef	pair<int,int>	Picture;

Picture	p[MAX_NUM_OF_PICTURE];
int		dp[MAX_NUM_OF_PICTURE];

int	main(void)
{
	int	N,S;
	
	scanf("%d %d",&N,&S);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d %d",&p[i].first,&p[i].second);	
	}
	sort(&p[1],&p[N+1]);
	
	p[0].first = p[0].second = 0;
	dp[0] = 0;
	
	for(int i=1;i<=N;i++)
	{
		int&	current_picture_height = p[i].first;
		int&	current_picture_value = p[i].second;
		
		int	lo,hi,mid,front_picture_index;
		
		lo = 0;
		hi = i-1;
		front_picture_index = 0;
		
		while(lo<=hi)
		{
			mid = (lo+hi)/2;
			
			if( p[mid].first+S <= current_picture_height )
			{
				lo = mid+1;
				
				if( mid > front_picture_index )
				{
					front_picture_index = mid;
				}
			}
			else
			{
				hi = mid-1;
			}
		}
				
		dp[i] = max(current_picture_value+dp[front_picture_index],dp[i-1]);
	}
	
	cout<<dp[N]<<endl;
	
	return	0;	
}
