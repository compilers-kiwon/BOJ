#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_PLAYER	(10000+1)

typedef	struct	_PLAYER_INFO	Player;
struct	_PLAYER_INFO
{
	int	index,S,C,L;
};

Player	p[MAX_NUM_OF_PLAYER];

bool	is_better(const Player& p1,const Player& p2)
{
	bool	result;
	
	if( p1.S > p2.S )
	{
		result = true;
	}
	else if( p1.S < p2.S )
	{
		result = false;
	}
	else
	{
		if( p1.C < p2.C )
		{
			result = true;
		}
		else if( p1.C > p2.C )
		{
			result = false;
		}
		else
		{
			if( p1.L < p2.L )
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
	}
	
	return	result;
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		p[i].index = i;
		cin>>p[i].S>>p[i].C>>p[i].L;
	}
	
	sort(&p[1],&p[N+1],is_better);
	cout<<p[1].index<<endl;
	
	return	0;
}
