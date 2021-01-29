#include	<iostream>

using namespace std;

#define	MAX_SIZE	(500+1)
#define	abs(n)		((n)>=0?(n):-(n))

typedef	pair<int,int>	Pos;	// first:X,second:Y

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,max_distance,c1,c2;
	Pos	cow[MAX_SIZE];
	
	cin>>N;
	max_distance = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>cow[i].first>>cow[i].second;
	}
	
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			int	dx,dy;
			
			dx = abs(cow[i].first-cow[j].first);
			dy = abs(cow[i].second-cow[j].second);
			
			if( max_distance < dx+dy )
			{
				max_distance = dx+dy;
				c1 = i;
				c2 = j;
			}
		}
	}
	
	cout<<c1<<' '<<c2<<'\n';
	
	return	0;
}
