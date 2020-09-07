#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int		n,m;
int		max_len;
int		state[MAX_SIZE][MAX_SIZE];
char	map[MAX_SIZE][MAX_SIZE+1];


int	main(void)
{
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=m;i++)
	{
		map[0][i] = '0';
		state[0][i] = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		map[i][0] = '0';
		state[i][0] = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&map[i][1]);
		
		for(int j=1;j<=m;j++)
		{
			if( map[i][j] == '0' )
			{
				state[i][j] = 0;
			}
			else
			{
				state[i][j] = 1;
			}
		}
	}
	
	max_len = 0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if( state[i][j] == 0 )
			{
				continue;
			}
			
			int	a,b,c;
			
			a = state[i-1][j-1];
			b = state[i-1][j];
			c = state[i][j-1];
			
			state[i][j] += min(a,min(b,c));
			max_len = max(max_len,state[i][j]);
		}
	}
	printf("%d\n",max_len*max_len);
	
	return	0;
}


