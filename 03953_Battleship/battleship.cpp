#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	30
#define	MAX_SHOT	(2000+1)

#define	WATER	'_'
#define	SHIP	'#'

#define	PLAYER_1	0
#define	PLAYER_2	1
#define	MAX_PLAYER	2

#define	NEXT_PLAYER(p)	(((p)+1)%MAX_PLAYER)

typedef	pair<int,int>	Pos;	//first:x,second:y

int		w,h,n,num_of_ships[MAX_PLAYER];
char	map[MAX_PLAYER][MAX_SIZE][MAX_SIZE+1];
Pos		shot[MAX_SHOT];

void	input(void)
{
	scanf("%d %d %d",&w,&h,&n);
	
	for(int p=PLAYER_1;p<=PLAYER_2;p++)
	{
		num_of_ships[p] = 0;
		
		for(int y=h-1;y>=0;y--)
		{
			scanf("%s",&map[p][y][0]);
			
			for(int x=0;x<w;x++)
			{
				if( map[p][y][x] == SHIP )
				{
					num_of_ships[p]++;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&shot[i].first,&shot[i].second);
	}
}

void	shot_ship(int offense,int target,int& shot_idx)
{
	for(;shot_idx<=n;shot_idx++)
	{
		int&	x = shot[shot_idx].first;
		int&	y = shot[shot_idx].second;
		
		if( map[target][y][x] != SHIP )
		{
			shot_idx++;
			break;
		}
		
		map[target][y][x] = WATER;
		num_of_ships[target]--;
		
		if( num_of_ships[target] == 0 )
		{
			shot_idx++;
			break;
		}
	}
}

int		simulate(void)
{
	for(int s=1;s<=n;)
	{
		shot_ship(PLAYER_1,PLAYER_2,s);
		shot_ship(PLAYER_2,PLAYER_1,s);
		
		if( num_of_ships[PLAYER_1]==0 && num_of_ships[PLAYER_2]==0 )
		{
			break;
		}
		
		if( num_of_ships[PLAYER_1] == 0 )
		{
			return	PLAYER_2;
		}
		
		if( num_of_ships[PLAYER_2] == 0 )
		{
			return	PLAYER_1;
		}
	}
	
	return	MAX_PLAYER;
}

int		main(void)
{
	int	t;
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++)
	{
		int	result;
		
		input();
		result = simulate();
		
		switch(result)
		{
			case	PLAYER_1 :
				puts("player one wins");
				break;
			case	PLAYER_2 :
				puts("player two wins");
				break;
			default:
				puts("draw");
				break;
		}
	}
	
	return	0;
}
