#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PARTS	(300+1)
#define	MAX_NUM_OF_TEST		(1000+1)

#define	ERROR	0
#define	CORRECT	1
#define	UNKNOWN	2

#define	PASS	1
#define	FAIL	0

#define	POWER		0
#define	MOTOR		1
#define	CABLE		2
#define	RESULT		3

int	main(void)
{
	int		result_table[MAX_NUM_OF_TEST][RESULT+1];
	int		parts_state[MAX_NUM_OF_PARTS],num_of_parts;
	int		a,b,c,N;
	bool	updated;
	
	cin.sync_with_stdio(false);
	
	cin>>a>>b>>c>>N;
	num_of_parts = a+b+c;
	
	for(int i=1;i<=num_of_parts;i++)
	{
		parts_state[i] = UNKNOWN;
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>result_table[i][POWER]>>result_table[i][MOTOR]>>result_table[i][CABLE]>>result_table[i][RESULT];
	}
	
	updated = true;
	
	while( updated != false )
	{
		int	n;
		
		for(n=1;n<=N;n++)
		{
			int&	i = result_table[n][POWER];
			int&	j = result_table[n][MOTOR];
			int&	k = result_table[n][CABLE];
			int&	r = result_table[n][RESULT];
			
			if( r == PASS )
			{
				if( parts_state[i]!=CORRECT || parts_state[j]!=CORRECT || parts_state[k]!=CORRECT )
				{
					parts_state[i] = parts_state[j] = parts_state[k] = CORRECT;
					break;
				} 
			}
			else
			{
				if( parts_state[i]==UNKNOWN && (parts_state[j]==CORRECT&&parts_state[k]==CORRECT) )
				{
					parts_state[i] = ERROR;
					break;
				}
				
				if( parts_state[j]==UNKNOWN && (parts_state[i]==CORRECT&&parts_state[k]==CORRECT) )
				{
					parts_state[j] = ERROR;
					break;
				}
				
				if( parts_state[k]==UNKNOWN && (parts_state[i]==CORRECT&&parts_state[j]==CORRECT) )
				{
					parts_state[k] = ERROR;
					break;
				}
			}
		}
		
		if( n > N )
		{
			updated = false;
		}
	}
	
	for(int i=1;i<=num_of_parts;i++)
	{
		cout<<parts_state[i]<<'\n';
	}
	
	return	0;
}
