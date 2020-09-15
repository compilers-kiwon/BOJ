#include	<iostream>
#include	<set>

using namespace	std;

#define	MAX_DIR	8
#define	START_X	1
#define	START_Y	1
#define	INF		0x7FFFFFFF

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{2,1},{2,-1},{-2,1},{-2,-1},{-1,2},{1,2},{-1,-2},{1,-2}};

#define	get_number(x,y)	(((x)+(y)-1)*((x)+(y)-2)/2+(y))

int	main(void)
{
	int			x,y,n,k;
	set<int>	visited;
	
	x = START_X;
	y = START_Y;
	
	n = 1;
	visited.insert(1);
	
	cin>>k;
	
	for(int i=1;i<=k;i++)
	{
		int	next_x,next_y,next_n;
		
		next_n = INF;
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int	adj_x,adj_y;
			
			adj_x = x+adj[d].dx;
			adj_y = y+adj[d].dy;
			
			if( adj_x>0 && adj_y>0 )
			{
				int	v;
				
				v = get_number(adj_x,adj_y);
				
				if( visited.find(v)==visited.end() && v<next_n )
				{
					next_x = adj_x;
					next_y = adj_y;
					next_n = v;
				}
			}
		}	
		
		if( next_n == INF )
		{
			break;
		}
		
		x = next_x;
		y = next_y;
		
		n = next_n;
		visited.insert(n);
	}
	
	cout<<n<<'\n';
	
	return	0;	
}
