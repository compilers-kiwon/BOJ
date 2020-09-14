#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	LIFE	'*'
#define	EMPTY	'.'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// first:row,second:col

int		N,M,T,K,a,b,cnt[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];

void	input(void)
{
	cin>>N>>M>>T>>K>>a>>b;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=M;col++)
		{
			cnt[row][col] = cnt[row][col-1]+((grid[row][col]==LIFE)?1:0);
		}
	}
}

int		get_num_of_life(int row,int col)
{
	int	s_row,e_row,s_col,e_col,ret;
	
	ret = 0;
	s_row = max(1,row-K),e_row = min(N,row+K);
	s_col = max(1,col-K),e_col = min(M,col+K);
	
	for(int i=s_row;i<=e_row;i++)
	{
		ret += cnt[i][e_col]-cnt[i][s_col-1];
	}
	
	return	ret;
}

void	simulate(void)
{
	for(int t=1;t<=T;t++)
	{
		vector<Pos>	birth,death;
		
		for(int row=1;row<=N;row++)
		{
			for(int col=1;col<=M;col++)
			{
				char&	c = grid[row][col];
				int		n;
				
				n = get_num_of_life(row,col);
				
				if( c == LIFE )
				{
					if( IN_RANGE(a,n-1,b) == true )
					{
						// do nothing
					}
					else
					{
						death.push_back(make_pair(row,col));
					}
				}
				else
				{
					if( IN_RANGE(a+1,n,b) == true )
					{
						birth.push_back(make_pair(row,col));
					}
				}
			}
		}
		
		for(int i=0;i<birth.size();i++)
		{
			int&	r = birth[i].first;
			int&	c = birth[i].second;
			
			grid[r][c] = LIFE;
		}
		
		for(int i=0;i<death.size();i++)
		{
			int&	r = death[i].first;
			int&	c = death[i].second;
			
			grid[r][c] = EMPTY;
		}
		
		for(int row=1;row<=N;row++)
		{
			for(int col=1;col<=M;col++)
			{
				cnt[row][col] = cnt[row][col-1]+((grid[row][col]==LIFE)?1:0);
			}
		}
	}
}

void	print(void)
{
	for(int row=1;row<=N;row++)
	{
		cout<<&grid[row][1]<<'\n';
	}
}

int		main(void)
{
	input();
	simulate();
	print();
	
	return	0;
}
