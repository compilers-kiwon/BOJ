#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	EMPTY	'.'
#define	FIRE	'F'
#define	WALL	'#'
#define	PERSON	'J'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

bool	visited[MAX_SIZE][MAX_SIZE];
char	maze[MAX_SIZE][MAX_SIZE+1];
int		R,C;

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	time,row,col;
};

int		escape(void)
{
	queue<State>	person_q;
	queue<State>	fire_q;
	int				min_time;
	bool			found;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( maze[row][col] == FIRE )
			{
				State	fire;
				
				fire.row = row;
				fire.col = col;
				fire_q.push(fire);
			}
			else if( maze[row][col] == PERSON )
			{
				State	person;
				
				person.time = 0;
				person.row = row;
				person.col = col;
				person_q.push(person);
				
				maze[row][col] = EMPTY;
				visited[row][col] = true;
			}
		}
	}
	
	min_time = 0x7FFFFFFF;
	found = false;
		
	while( person_q.size() != 0 && found == false )
	{
		for(int i=1,fire_q_size=fire_q.size();i<=fire_q_size;i++)
		{
			int	current_fire_row,current_fire_col;
			
			current_fire_row = fire_q.front().row;
			current_fire_col = fire_q.front().col;
			
			fire_q.pop();
			
			for(int j=UP;j<=RIGHT;j++)
			{
				int	next_fire_row,next_fire_col;
				
				next_fire_row = current_fire_row+adj[j].d_row;
				next_fire_col = current_fire_col+adj[j].d_col;
				
				if( IN_RANGE(1,next_fire_row,R) && IN_RANGE(1,next_fire_col,C) )
				{
					if( maze[next_fire_row][next_fire_col] == EMPTY )
					{
						State	next_fire;
						
						next_fire.row = next_fire_row;
						next_fire.col = next_fire_col;
						fire_q.push(next_fire);
						
						maze[next_fire_row][next_fire_col] = FIRE;
					}
				}
			}
		}
					
		for(int i=1,person_q_size=person_q.size();i<=person_q_size;i++)
		{
			int	current_person_time,current_person_row,current_person_col;
		
			current_person_time = person_q.front().time;
			current_person_row = person_q.front().row;
			current_person_col = person_q.front().col;
			
			person_q.pop();
			
			if( current_person_row == 1 || current_person_row == R || current_person_col == 1 || current_person_col == C )
			{
				min_time = current_person_time+1;
				found = true;
				break;
			}
			
			for(int j=UP;j<=RIGHT;j++)
			{
				int	next_person_row,next_person_col;
				
				next_person_row = current_person_row+adj[j].d_row;
				next_person_col = current_person_col+adj[j].d_col;
				
				if( IN_RANGE(1,next_person_row,R) && IN_RANGE(1,next_person_col,C) )
				{
					if( maze[next_person_row][next_person_col] == EMPTY && visited[next_person_row][next_person_col] == false )
					{
						State	next_person;
						
						next_person.time = current_person_time+1;
						next_person.row = next_person_row;
						next_person.col = next_person_col;
						person_q.push(next_person);
						
						visited[next_person_row][next_person_col] = true;
					}
				}
			}
		}
	} 
	
	return	min_time;
}

int		main(void)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&maze[row][1]);
	}
	
	int	min_time;
	
	min_time = escape();
	
	if( min_time == 0x7FFFFFFF )
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		cout<<min_time<<endl;
	}
	
	return	0;
}
