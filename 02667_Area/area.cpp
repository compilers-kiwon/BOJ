#include	<cstdio>
#include	<vector>
#include	<algorithm>

using namespace std;

#define	MAX_SIZE			(25+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	HOUSE	'1'
#define	EMPTY	'0'

#define	IN_RANGE(N,MIN,MAX)	(((N)>=(MIN) && (N)<=(MAX))?true:false)

char	map[MAX_SIZE][MAX_SIZE+1];
int		N;

struct{
	int	row,col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};


void	find_num_of_adj_house(int current_row,int current_col,int& current_num_of_adj_house)
{
	for(int i=UP;i<=RIGHT;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = current_row+adj[i].row;
		adj_col = current_col+adj[i].col;
		
		if( IN_RANGE(adj_row,1,N) && IN_RANGE(adj_col,1,N) && map[adj_row][adj_col] == HOUSE )
		{
			map[adj_row][adj_col] = EMPTY;
			++current_num_of_adj_house;
			find_num_of_adj_house(adj_row,adj_col,current_num_of_adj_house);
		}
	}
}

int		main(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&map[i][1]);
	}
	
	vector<int>	cnt_of_adj_house;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if( map[i][j] == HOUSE )
			{
				int	n = 1;
				
				map[i][j] = EMPTY;
				find_num_of_adj_house(i,j,n);
				cnt_of_adj_house.push_back(n);
			}
		}
	}
	
	printf("%d\n",cnt_of_adj_house.size());
	
	sort(cnt_of_adj_house.begin(),cnt_of_adj_house.end());
	
	for(int i=0;i<cnt_of_adj_house.size();i++)
	{
		printf("%d\n",cnt_of_adj_house[i]);
	}
	
	return	0;
}
