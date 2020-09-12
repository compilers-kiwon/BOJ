#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	1000

char	map[MAX_SIZE][MAX_SIZE];

#define	EMPTY	'*'
#define	BARRIER	'x'
#define	VISITED	' '

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<(MAX))

#define	UP		1
#define	DOWN	2
#define	LEFT	3
#define	RIGHT	4
#define	MAX_DIR	5

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{0,0},{-1,0},{1,0},{0,-1},{0,1}};

pair<int,int>	move(pair<int,int>& current,pair<int,int>& max_size,
					 vector<int>& instruction,int current_instruction,
					 int prev_stop_instruction)
{
	if( current_instruction == instruction.size() )
	{
		current_instruction = 0;
	}
	
	if( current_instruction == prev_stop_instruction )
	{
		return	current;
	}
	
	int	current_dir,next_row,next_col,cnt,next_stop_instruction;
	
	current_dir = instruction[current_instruction];
	cnt = 0;
		
	while(1)
	{
		next_row = current.first+adj[current_dir].d_row;
		next_col = current.second+adj[current_dir].d_col;
	
		if( IN_RANGE(0,next_row,max_size.first) && IN_RANGE(0,next_col,max_size.second) && map[next_row][next_col] == EMPTY )
		{
			map[current.first][current.second] = VISITED;
			current = make_pair(next_row,next_col);
			cnt++;
		}
		else
		{
			break;
		}
	}
	
	if( prev_stop_instruction != -1 && cnt == 0 )
	{
		next_stop_instruction = prev_stop_instruction;
	}
	else
	{
		next_stop_instruction = current_instruction;
	}
	
	return	move(current,max_size,instruction,current_instruction+1,next_stop_instruction);
}

int		main(void)
{
	pair<int,int>	map_size,init,final;
	int				k,sr,sc;
	vector<int>		instruction;
	
	cin>>map_size.first>>map_size.second;
	
	for(int row=0;row<map_size.first;row++)
	{
		for(int col=0;col<map_size.second;col++)
		{
			map[row][col] = EMPTY;
		}
	}
	
	cin>>k;
	
	for(int i=1;i<=k;i++)
	{
		int	br,bc;
		
		cin>>br>>bc;
		map[br][bc] = BARRIER;
	}
	
	cin>>sr>>sc;
	
	for(int i=1;i<=4;i++)
	{
		int 	n;
		
		cin>>n;
		instruction.push_back(n);
	}
	
	map[sr][sc] = VISITED;
	
	init = make_pair(sr,sc);
	final = move(init,map_size,instruction,0,-1);
	
	cout<<final.first<<' '<<final.second<<endl;
	
	return	0;	
}
