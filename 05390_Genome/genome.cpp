#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(100000+1)
#define	MIN_INIT		0x7FFFFFFF
#define	MAX_INIT		0

#define	NUM_OF_GENOME	2
#define	FIRST_GENOME	0
#define	SECOND_GENOME	1

#define	NONE	0

int	genome[NUM_OF_GENOME][MAX_SIZE],visited_cnt[MAX_SIZE];

void	input(int& length_of_genome)
{
	cin>>length_of_genome;
	
	for(int i=1;i<=length_of_genome;i++)
	{
		cin>>genome[FIRST_GENOME][i];
	}
	
	for(int i=1;i<=length_of_genome;i++)
	{
		cin>>genome[SECOND_GENOME][i];
	}
}

void	compare_genome(int length_of_genome)
{
	int	s,e,cnt;
		
	s = e = cnt = NONE;
	fill(&visited_cnt[1],&visited_cnt[length_of_genome+1],0);
	
	for(int i=1;i<=length_of_genome;i++)
	{
		if( s == NONE )
		{
			s = i;
		}
		
		int&	g1 = genome[FIRST_GENOME][i];
		int&	g2 = genome[SECOND_GENOME][i];
		
		if( (++visited_cnt[g1]) == NUM_OF_GENOME )
		{
			cnt--;
		}
		else
		{
			cnt++;
		}
		
		if( (++visited_cnt[g2]) == NUM_OF_GENOME )
		{
			cnt--;
		}
		else
		{
			cnt++;
		}
		
		if( cnt == NONE )
		{
			e = i;
		}
		
		if( s!=NONE && e!=NONE )
		{
			cout<<s<<'-'<<e<<(e==length_of_genome?'\n':' ');
			s = e = cnt = NONE;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	N;
		
		input(N);
		compare_genome(N);
	}
	
	return	0;
}
