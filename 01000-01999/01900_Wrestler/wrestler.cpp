#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_WRESTLER	(10000+1)

typedef	struct	_WRESTLER_INFO	Wrestler;
struct	_WRESTLER_INFO
{
	int	power,ring,index;
};

int			N;
Wrestler	wrestler[MAX_NUM_OF_WRESTLER];

bool	is_stronger(const Wrestler& w1,const Wrestler& w2)
{
	int	w1_ability,w2_ability;
	
	w1_ability = w1.power+w2.power*w1.ring;
	w2_ability = w2.power+w1.power*w2.ring;
	
	return	(w1_ability>w2_ability);
}

void	input(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d %d",&wrestler[i].power,&wrestler[i].ring);
		wrestler[i].index = i;		
	}
}

int		main(void)
{
	input();
	
	sort(&wrestler[1],&wrestler[N+1],is_stronger);
	
	for(int i=1;i<=N;i++)
	{
		printf("%d\n",wrestler[i].index);
	}
	
	return	0;
}
