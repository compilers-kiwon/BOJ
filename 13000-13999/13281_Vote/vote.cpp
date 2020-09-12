#include	<iostream>

using namespace	std;

#define	MAX_VOTE	(100+1)
#define	MAX_SIZE	0x100

typedef	pair<char,int>	Candidate;

bool	input(int& num_of_vote,char* vote)
{
	cin>>num_of_vote;
	
	if( num_of_vote == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=num_of_vote;i++)
	{
		cin>>vote[i];
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		n,i,vote[MAX_SIZE];
		char	c[MAX_VOTE];
		
		if( input(n,c) == false )
		{
			break;
		}
		
		fill(&vote['A'],&vote['Z'+1],0);
		
		Candidate	first,second;
		
		first = make_pair('A',0);
		second = make_pair('B',0);
		
		for(i=1;i<=n;i++)
		{
			char&	v = c[i];
			
			vote[v]++;
			
			if( v == first.first )
			{
				first.second++;
			}
			else
			{
				Candidate	tmp;
				
				if( v == second.first )
				{
					second.second++;
					tmp = second;
				}
				else
				{
					tmp = make_pair(v,vote[v]);
				}
				
				if( tmp.second > first.second )
				{
					second = first;
					first = tmp;
				}
				else
				{
					if( tmp.second > second.second )
					{
						second = tmp;
					}
				}
			}
			
			int	rest_vote,diff;
			
			rest_vote = n-i;
			diff = first.second-second.second;
			
			if( rest_vote < diff )
			{
				break;
			}
		}
		
		if( first.second == second.second )
		{
			cout<<"TIE\n";
		}
		else
		{
			cout<<first.first<<' '<<i<<'\n';
		}
	}
	
	return	0;
}
