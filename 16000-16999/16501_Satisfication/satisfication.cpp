#include	<iostream>
#include	<cmath>
#include	<cstring>

using namespace	std;

#define	NUM_OF_PLAYER	8

double	ability[NUM_OF_PLAYER+1];
int		player_order[NUM_OF_PLAYER+1];
bool	arranged[NUM_OF_PLAYER+1];

#define	get_avg(d1,d2)	(((d1)+(d2))/2.0)
#define	BUF_LEN			10

double	get_satisfication(void)
{
	double	t1,t2,t3,t4;
	
	t1 = get_avg(ability[player_order[1]],ability[player_order[2]]);
	t2 = get_avg(ability[player_order[3]],ability[player_order[4]]);
	t3 = get_avg(ability[player_order[5]],ability[player_order[6]]);
	t4 = get_avg(ability[player_order[7]],ability[player_order[8]]);
	
	return	min(1.0-abs(t1-t2)/10.0,1.0-abs(t3-t4)/10.0);	
}

void	build_team(int order_index,double& max_satisfication)
{
	if( order_index > NUM_OF_PLAYER )
	{
		max_satisfication = max(max_satisfication,get_satisfication());
		return;
	}
	
	for(int i=1;i<=NUM_OF_PLAYER;i++)
	{
		if( arranged[i] == false )
		{
			arranged[i] = true;
			player_order[order_index] = i;
			
			build_team(order_index+1,max_satisfication);
			
			arranged[i] = false;
		}
	}
}

int		main(void)
{
	for(int i=1;i<=NUM_OF_PLAYER;i++)
	{
		cin>>ability[i];
	}
	
	double	max_satisfication;
	char	buf[BUF_LEN+1];
	int		last;
	
	max_satisfication = 0.0;
	build_team(1,max_satisfication);
	
	sprintf(buf,"%.2f",max_satisfication);
	
	for(last=strlen(buf)-1;buf[last]=='0';last--);
	
	if( buf[last] == '.' )
	{
		last++;
	}
	buf[last+1] = '\0';
	
	puts(buf);
	
	return	0;
}
