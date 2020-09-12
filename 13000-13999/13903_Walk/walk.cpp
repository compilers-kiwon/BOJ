#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	HORI	0
#define	VERT	1

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

typedef	pair<int,int>	Adj;	// first:row, second:col
typedef	pair<int,Adj>	State;	// first:num of movement, second:<row,col>

int	map[MAX_SIZE][MAX_SIZE],walk_table[MAX_SIZE][MAX_SIZE];

int	find_min_walk(int max_row,int max_col,int num_of_rule,vector<Adj>& rule)
{
	priority_queue<State>	pq;
	
	for(int i=1;i<=max_col;i++)
	{
		if( map[1][i] == VERT )
		{
			pq.push(make_pair(0,make_pair(1,i)));
			walk_table[1][i] = 0;
		}
	}
	
	while( !pq.empty() )
	{
		int	current_walk,current_row,current_col;
		
		current_walk = -pq.top().first;
		current_row  = pq.top().second.first;
		current_col  = pq.top().second.second;
		
		pq.pop();
		
		if( current_walk > walk_table[current_row][current_col] )
		{
			continue;
		}
		
		if( current_row == max_row )
		{
			return	current_walk;
		}
		
		int	next_walk,next_row,next_col;
		
		next_walk = current_walk+1;
		
		for(int i=0;i<num_of_rule;i++)
		{
			next_row = current_row+rule[i].first;
			next_col = current_col+rule[i].second;
			
			if( IN_RANGE(1,next_row,max_row) && IN_RANGE(1,next_col,max_col) )
			{
				if( map[next_row][next_col] == VERT && next_walk < walk_table[next_row][next_col] )
				{
					walk_table[next_row][next_col] = next_walk;
					pq.push(make_pair(-next_walk,make_pair(next_row,next_col)));
				}
			}
		}
	}
	
	return	-1;
}

int	main(void)
{
	int			R,C,N;
	vector<Adj>	rule;
	
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			cin>>map[row][col];
			walk_table[row][col] = 0x7FFFFFFF;
		}
	}
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	r,c;
		
		cin>>r>>c;
		rule.push_back(make_pair(r,c));
	}
	
	cout<<find_min_walk(R,C,N,rule)<<endl;
	
	return	0;
}
