#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_COWS	(100000+1)
#define	MAX_SIZE		100000000

typedef	pair<int,int>	Pos;

#define	x	first
#define	y	second
	
int		N,M,parent[MAX_NUM_OF_COWS];
Pos		p[MAX_NUM_OF_COWS];
bool	visited[MAX_NUM_OF_COWS];

vector<int>	connected[MAX_NUM_OF_COWS];

void	get_coordinates(void)
{
	for(int i=1;i<=N;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
}

void	get_connections(void)
{
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		
		connected[a].push_back(b);
		connected[b].push_back(a);
	}
}

int		find_most_out_pos(int& bottom,int& top,int& left,int& right,int s_cow)
{
	queue<int>	cow_q;
	
	visited[s_cow] = true;
	cow_q.push(s_cow);
	
	for(;!cow_q.empty();)
	{
		int	current_cow;
		
		current_cow = cow_q.front();
		cow_q.pop();
		
		bottom = min(bottom,p[current_cow].y);
		top = max(top,p[current_cow].y);
		left = min(left,p[current_cow].x);
		right = max(right,p[current_cow].x);
		
		vector<int>&	adj_cows = connected[current_cow];
		
		for(int i=0;i<adj_cows.size();i++)
		{
			int&	adj_cow = adj_cows[i];
			
			if( visited[adj_cow] == false )
			{
				visited[adj_cow] = true;
				cow_q.push(adj_cow);
			}
		}
	}
}

int		find_smallest_perimeter(void)
{
	int	ret;
	
	ret = 4*MAX_SIZE;
	
	for(int cow=1;cow<=N;cow++)
	{
		if( visited[cow] == false )
		{
			int	bottom,top,left,right;
			
			bottom = left = MAX_SIZE;
			top = right = 0;
			
			find_most_out_pos(bottom,top,left,right,cow);
			
			int	width,height;
			
			width = right-left;
			height = top-bottom;
			
			ret = min(ret,2*(width+height));
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	get_coordinates();
	get_connections();
	
	cout<<find_smallest_perimeter()<<'\n';
	
	return	0;
}
