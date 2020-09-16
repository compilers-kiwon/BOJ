#include	<iostream>
#include	<queue>

using namespace std;

#define	MAX_SIZE	(100+1)

#define	UP			0
#define	DOWN		1
#define	LEFT		2
#define	RIGHT		3
#define	BOX_UP		4
#define	BOX_DOWN	5
#define	MAX_DIR		6

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

int	lattice[MAX_SIZE][MAX_SIZE][MAX_SIZE];	// Z,Y,X

typedef	struct	_TOMATO	Tomato;
struct	_TOMATO
{
	int	day,z,y,x;
};

queue<Tomato> done;	

int	H,N,M;	// Z,Y,X
int	num_of_done_tomato,num_of_tomato;

struct _ADJ {
	int	z,y,x;
} adj_tomato[MAX_DIR] = {{0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0}};

int	main(void)
{
	cin>>M>>N>>H;
	
	num_of_done_tomato = num_of_tomato = 0;
	
	int	z,y,x;
	
	for(z=1;z<=H;z++)
	{
		for(y=1;y<=N;y++)
		{
			for(x=1;x<=M;x++)
			{
				cin>>lattice[z][y][x];
			
				if( lattice[z][y][x] != -1 )
				{
					++num_of_tomato;
				
					if( lattice[z][y][x] == 1 )
					{
						Tomato	t;
						
						t.day = 0;
						t.x = x;
						t.y = y;
						t.z = z;
						done.push(t);
					}
				}
			}
		}
	}
	
	num_of_done_tomato = done.size();
	
	if( num_of_done_tomato == num_of_tomato )
	{
		cout<<"0\n";
		return	0;
	}
	
	int	answer=-1;
		
	while( done.size() != 0 )
	{
		int	today,current_done_tomato_z,current_done_tomato_y,current_done_tomato_x;
		
		today = done.front().day;
		current_done_tomato_z = done.front().z;
		current_done_tomato_y = done.front().y;
		current_done_tomato_x = done.front().x;
		done.pop();
		
		for(int i=UP;i<=BOX_DOWN;i++)
		{
			int	adj_tomato_z,adj_tomato_y,adj_tomato_x,adj_tomato_status;
			
			adj_tomato_z = current_done_tomato_z+adj_tomato[i].z;
			adj_tomato_y = current_done_tomato_y+adj_tomato[i].x;
			adj_tomato_x=  current_done_tomato_x+adj_tomato[i].y;
			
			if( IN_RANGE(1,adj_tomato_z,H) && IN_RANGE(1,adj_tomato_y,N) && IN_RANGE(1,adj_tomato_x,M) )
			{
				adj_tomato_status = lattice[adj_tomato_z][adj_tomato_y][adj_tomato_x];
				
				if( adj_tomato_status == 0 )
				{
					lattice[adj_tomato_z][adj_tomato_y][adj_tomato_x] = 1;
					
					Tomato	t;
					
					t.day = today+1;
					t.z = adj_tomato_z;
					t.y = adj_tomato_y;
					t.x = adj_tomato_x;
					
					done.push(t);
					
					++num_of_done_tomato;
				}
			}
		}
		
		if( num_of_done_tomato == num_of_tomato )
		{
			answer = today+1;
			break;
		}
	}
	cout<<answer<<endl;
	
	return	0;
}
