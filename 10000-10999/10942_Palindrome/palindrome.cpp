#include	<iostream>

using namespace	std;

#define	MAX_LEN	(2000+1)

#define	TRUE	1
#define	FALSE	0
#define	UNKNOWN	-1

int	number[MAX_LEN];
int	dp[MAX_LEN][MAX_LEN];

int	is_palindrome(int S,int E)
{
	if( S==E || S>E )
	{
		return	TRUE;
	}
	
	if( dp[S][E] != UNKNOWN )
	{
		return	dp[S][E];
	}
		
	if( number[S] == number[E] )
	{
		dp[S][E] = is_palindrome(S+1,E-1);
	}
	else
	{
		dp[S][E] = FALSE;
	}
	
	return	dp[S][E];
}

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&number[i]);
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dp[i][j] = UNKNOWN;
		}
		dp[i][i] = TRUE;
	}
	
	int	M;
	
	scanf("%d",&M);
	
	for(int i=1;i<=M;i++)
	{
		int	S,E,s,e;
		
		scanf("%d %d",&S,&E);
		
		s = min(S,E);
		e = max(S,E);
		
		printf("%d\n",is_palindrome(s,e));
	}
	
	return	0;
}
