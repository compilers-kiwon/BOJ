#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(14+1)

bool	visited_col[MAX_SIZE],visited_SE[2*MAX_SIZE],visited_SW[2*MAX_SIZE];
int		N,answer;

void	place_queen(int queen_to_be_placed)
{
	if( queen_to_be_placed > N )
	{
		answer++;
		return;
	}
	
	for(int i=1;i<=N;i++)
	{
		if( visited_col[i]==false && visited_SE[queen_to_be_placed-i+MAX_SIZE]==false
			&& visited_SW[queen_to_be_placed+i]==false )
		{
			visited_col[i] = visited_SE[queen_to_be_placed-i+MAX_SIZE] 
				= visited_SW[queen_to_be_placed+i] = true;
				
			place_queen(queen_to_be_placed+1);
			
			visited_col[i] = visited_SE[queen_to_be_placed-i+MAX_SIZE] 
				= visited_SW[queen_to_be_placed+i] = false;
			
		}
	}
}

int		main(void)
{
	cin>>N;
	place_queen(1);
	cout<<answer;
	
	return	0;
}
