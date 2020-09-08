#include	<iostream>

using namespace	std;

#define	NUM_OF_ROUNDS	10

int	main(void)
{
	int	A[NUM_OF_ROUNDS+1],B[NUM_OF_ROUNDS+1];
	
	for(int i=1;i<=NUM_OF_ROUNDS;i++)
	{
		cin>>A[i];
	}
	
	for(int i=1;i<=NUM_OF_ROUNDS;i++)
	{
		cin>>B[i];
	}
	
	int	A_win,B_win;
	
	A_win = B_win = 0;
	
	for(int i=1;i<=NUM_OF_ROUNDS;i++)
	{
		if( A[i] > B[i] )
		{
			A_win++;
		}
		else if( A[i] < B[i] )
		{
			B_win++;
		}
	}
	
	char	winner;
	
	if( A_win > B_win )
	{
		winner = 'A';
	}
	else if( A_win < B_win )
	{
		winner = 'B';
	}
	else
	{
		winner = 'D';
	}
	cout<<winner<<endl;
	
	return	0;
}
