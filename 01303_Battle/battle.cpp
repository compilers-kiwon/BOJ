#include	<iostream>

using namespace	std;

#define	ALLY	'W'
#define	ENEMY	'B'
#define	EMPTY	' '

#define	MAX_SIZE	(100+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

typedef	unsigned long long	uint64;

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N,M;
char	battle_field[MAX_SIZE][MAX_SIZE+1];

int		count_soldier(int current_row,int current_col,char soldier)
{
	int	cnt;
	
	cnt = 1;
	battle_field[current_row][current_col] = EMPTY;
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	next_row,next_col;
		
		next_row = current_row+adj[i].d_row;
		next_col = current_col+adj[i].d_col;
		
		if( IN_RANGE(1,next_row,N) && IN_RANGE(1,next_col,M) && battle_field[next_row][next_col] == soldier )
		{
			cnt += count_soldier(next_row,next_col,soldier);
		}
	}
	
	return	cnt;
}

int		main(void)
{
	scanf("%d %d",&M,&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&battle_field[i][1]);
	}
	
	uint64	ally_force,enemy_force;
	
	ally_force = enemy_force = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			char	soldier;
			int		num_of_soldier;
			
			soldier = battle_field[i][j];
			
			if( soldier != EMPTY )
			{
				num_of_soldier = count_soldier(i,j,soldier);
			
				if( soldier == ALLY )
				{
					ally_force += num_of_soldier*num_of_soldier;
				}
				else
				{
					enemy_force += num_of_soldier*num_of_soldier;
				}
			}
		}
	}
	
	printf("%llu %llu\n",ally_force,enemy_force);
	
	return	0;
}
