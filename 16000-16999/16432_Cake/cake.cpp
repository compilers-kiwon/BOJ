#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_DAY	(1000+1)

vector<int>	available_cake[MAX_DAY];
int			N,cake_for_tiger[MAX_DAY+1];

bool	dfs(int prev_day,int today)
{
	if( today == prev_day )
	{
		return	true;
	}
	
	vector<int>&	today_cake = available_cake[today];
	
	for(int i=0;i<today_cake.size();i++)
	{
		int&	cake = today_cake[i];
		
		if( cake!=cake_for_tiger[today-1] && cake!=cake_for_tiger[today+1] )
		{
			cake_for_tiger[today] = cake;
			
			if( dfs(prev_day,today-1) == true )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	bool	flag;
	int		prev;
	
	scanf("%d",&N);
	
	flag = true;
	prev = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	m,a;
		
		scanf("%d",&m);
				
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a);
			available_cake[i].push_back(a);
		}
		
		if( m == 1 )
		{
			if( dfs(prev,i) == false )
			{
				flag = false;
				break;
			}
			prev = i;
		}
	}
	
	if( flag==false || dfs(prev,N)==false )
	{
		puts("-1");
	}
	else
	{
		for(int i=1;i<=N;i++)
		{
			printf("%d\n",cake_for_tiger[i]);
		}
	}
	
	return	0;
}
