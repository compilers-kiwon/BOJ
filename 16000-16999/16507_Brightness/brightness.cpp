#include	<iostream>

using namespace	std;

typedef	long long int	int64;

#define	MAX_SIZE	(1000+1)

int		R,C,Q;
int64	acc_brightness[MAX_SIZE][MAX_SIZE];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>R>>C>>Q;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			int64	b;
			
			cin>>b;
			acc_brightness[row][col] = acc_brightness[row][col-1]+b;
		}
	}
}

int64	get_avg_brightness(int r1,int c1,int r2,int c2)
{
	int64	sum;
	
	sum = 0;
	
	for(int row=r1;row<=r2;row++)
	{
		sum += acc_brightness[row][c2]-acc_brightness[row][c1-1];
	}
	
	return	sum/(int64)((r2-r1+1)*(c2-c1+1));
}

int		main(void)
{
	init();
	
	for(int i=1;i<=Q;i++)
	{
		int	r1,c1,r2,c2;
		
		cin>>r1>>c1>>r2>>c2;
		cout<<get_avg_brightness(r1,c1,r2,c2)<<'\n';
	}
	
	return	0;
}
