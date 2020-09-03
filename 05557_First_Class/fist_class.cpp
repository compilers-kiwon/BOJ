#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_NUMS		(100+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))
#define	MIN_NUM				0
#define	MAX_NUM				20

typedef	unsigned long long	uint64;

uint64	interim_value[MAX_NUM_OF_NUMS][MAX_NUM-MIN_NUM+1];

int		main(void)
{
	int	N,n[MAX_NUM_OF_NUMS];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>n[i];
	}
	
	interim_value[1][n[1]] = 1;
	
	for(int i=1;i<N-1;i++)
	{
		for(int j=MIN_NUM;j<=MAX_NUM;j++)
		{
			if( interim_value[i][j] != 0 )
			{
				int	op1,op2,interim;
				
				op1 = j;
				op2 = n[i+1]; 
				
				interim = op1+op2;
				
				if( IN_RANGE(MIN_NUM,interim,MAX_NUM) == true )
				{
					interim_value[i+1][interim] += interim_value[i][j];
				}
				
				interim = op1-op2;
				
				if( IN_RANGE(MIN_NUM,interim,MAX_NUM) == true )
				{
					interim_value[i+1][interim] += interim_value[i][j];
				}
			}
		}	
	}
	cout<<interim_value[N-1][n[N]]<<endl;
	
	return	0;	
}
