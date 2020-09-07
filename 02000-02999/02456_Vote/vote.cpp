#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_CANDIDATE	3
#define	NUM_OF_VOTE_CLASS	3

typedef	struct	_Candidate	Candidate;
struct	_Candidate
{
	int	index,sum,vote[NUM_OF_VOTE_CLASS+1];
};

Candidate	c[NUM_OF_CANDIDATE+1];	

bool	is_winner(Candidate& c1,Candidate& c2)
{
	if( c1.sum > c2.sum )
	{
		return	true;
	}
	else if( c1.sum < c2.sum )
	{
		return	false;
	}
	else
	{
		if( c1.vote[3] > c2.vote[3] )
		{
			return	true;
		}
		else if( c1.vote[3] < c2.vote[3] )
		{
			return	false;
		}
		else
		{
			if( c1.vote[2] > c2.vote[2] )
			{
				return	true;
			}
			else if( c1.vote[2] < c2.vote[2] )
			{
				return	false;
			}
		}
	}
	return	false;
}

int		main(void)
{
	int	N,w;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	v1,v2,v3;
		
		cin>>v1>>v2>>v3;
		
		c[1].vote[v1]++;
		c[2].vote[v2]++;
		c[3].vote[v3]++;
	}
	
	for(int i=1;i<=NUM_OF_CANDIDATE;i++)
	{
		c[i].sum = c[i].vote[3]*3+c[i].vote[2]*2+c[i].vote[1];
	}
	
	c[1].index = 1;
	c[2].index = 2;
	c[3].index = 3;
	
	sort(&c[1],&c[3+1],is_winner);
	
	if( c[1].sum == c[2].sum && c[1].vote[3] == c[2].vote[3] && c[1].vote[2] == c[2].vote[2] )
	{
		cout<<"0 "<<c[1].sum<<endl;
	}
	else
	{
		cout<<c[1].index<<' '<<c[1].sum<<endl;
	}
	
	return	0;
}
