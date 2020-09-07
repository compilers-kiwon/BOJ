#include	<iostream>

using namespace	std;

#define	NUM_OF_ROUNDS	10

int	A[NUM_OF_ROUNDS+1],B[NUM_OF_ROUNDS+1],A_score,B_score;

int	main(void)
{
	for(int i=1;i<=NUM_OF_ROUNDS;i++)
	{
		cin>>A[i];
	}
	
	for(int i=1;i<=NUM_OF_ROUNDS;i++)
	{
		cin>>B[i];
	}
	
	char	last_winner='D';
	
	for(int i=1;i<=NUM_OF_ROUNDS;i++)
	{
		if( A[i] > B[i] )
		{
			A_score += 3;
			last_winner = 'A';
		}
		else if( A[i] < B[i] )
		{
			B_score += 3;
			last_winner = 'B';
		}
		else
		{
			A_score++,B_score++;
		}
	}
	
	char	winner;
	
	if( A_score > B_score )
	{
		winner = 'A';
	}
	else if( A_score < B_score )
	{
		winner = 'B';
	}
	else
	{
		winner = last_winner;
	}
	
	cout<<A_score<<' '<<B_score<<endl<<winner<<endl;
	
	return	0;
}
