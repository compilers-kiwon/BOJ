#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_RUNNER	(1000000+1)
#define	MAX_BACK_NUMBER		1000000	
#define	NOT_DEFINED			0

int		back_number[MAX_NUM_OF_RUNNER][2];
int		matching_number[MAX_NUM_OF_RUNNER],matching_runner[MAX_BACK_NUMBER+1];
int		N,visited[MAX_NUM_OF_RUNNER];

void	input(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d %d",&back_number[i][0],&back_number[i][1]);
	}
}

bool	dfs(int runner,int turn)
{
	bool	result;
	
	visited[runner] = turn;
	
	for(int i=0;i<2;i++)
	{
		int	candidate;
		
		candidate = back_number[runner][i];
			
		if( matching_runner[candidate] == NOT_DEFINED || 
			(visited[matching_runner[candidate]] != turn && dfs(matching_runner[candidate],turn)) )
		{
			matching_number[runner] = candidate;
			matching_runner[candidate] = runner;
			result = true;
			
			break;
		}
		else
		{
			result = false;
		}
	}
	
	return	result;
}

int		main(void)
{
	bool	result;
	int		i;
	
	input();
	
	for(i=1,result=true;i<=N&&result!=false;i++)
	{
		if( matching_number[i] == NOT_DEFINED )
		{
			result = dfs(i,i);
		}
	}
	
	if( result == false )
	{
		puts("-1");
	}
	else
	{
		for(int i=1;i<=N;i++)
		{
			printf("%d\n",matching_number[i]);
		}
	}
	
	return	0;
}
