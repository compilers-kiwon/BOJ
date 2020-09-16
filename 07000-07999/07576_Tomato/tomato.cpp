#include	<iostream>
#include	<queue>

using namespace std;

#define	MAX_SIZE	(1000+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

int	lattice[MAX_SIZE][MAX_SIZE];

queue< pair< int,pair<int,int> > > done;	// day,<first:row,second:col>

int	N,M,num_of_done_tomato,num_of_tomato;

struct _ADJ {
	int	row,col;
} adj_tomato[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	main(void)
{
	cin>>M>>N;
	
	num_of_done_tomato = num_of_tomato = 0;
	
	int	i,j;
	
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			cin>>lattice[i][j];
			
			if( lattice[i][j] != -1 )
			{
				++num_of_tomato;
				
				if( lattice[i][j] == 1 )
				{
					done.push(make_pair(0,make_pair(i,j)));
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
		int	today,current_done_tomato_row,current_done_tomato_col;
		
		today = done.front().first;
		current_done_tomato_row = done.front().second.first;
		current_done_tomato_col = done.front().second.second;
		done.pop();
		
		for(i=UP;i<=RIGHT;i++)
		{
			int	adj_tomato_row,adj_tomato_col,adj_tomato_status;
			
			adj_tomato_row = current_done_tomato_row+adj_tomato[i].row;
			adj_tomato_col = current_done_tomato_col+adj_tomato[i].col;
			
			if( 1<=adj_tomato_row && adj_tomato_row<=N && 1<=adj_tomato_col && adj_tomato_col<=M )
			{
				adj_tomato_status = lattice[adj_tomato_row][adj_tomato_col];
				
				if( adj_tomato_status == 0 )
				{
					lattice[adj_tomato_row][adj_tomato_col] = 1;
					done.push(make_pair(today+1,make_pair(adj_tomato_row,adj_tomato_col)));
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
