#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(50+1)

typedef	pair<int,int>	Density;	// first:x,second:y

int		h,w,m,cnt_table[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];
bool	is_pixel[0x100];

void	input(void)
{
	string	p;
	
	cin>>h>>w>>m>>p;
	
	for(int row=1;row<=h;row++)
	{
		cin>>&grid[row][1];
	}
	
	fill(&is_pixel['A'],&is_pixel['Z'+1],false);
	
	for(int i=0;i<p.length();i++)
	{
		is_pixel[p[i]] = true;
	}
}

void	get_table(void)
{
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			cnt_table[row][col] = 
				cnt_table[row][col-1]+is_pixel[grid[row][col]];
		}
	}
}

int		get_cnt_of_pixel(int s_row,int s_col,int e_row,int e_col)
{
	int	ret;
	
	ret = 0;
	
	for(int row=s_row;row<=e_row;row++)
	{
		ret += cnt_table[row][e_col]-cnt_table[row][s_col-1];
	}
	
	return	ret;
}

void	find_max_density(Density& max_density)
{
	max_density.first = 0;
	max_density.second = min(h,w)*min(h,w);
	
	for(int s_row=1;s_row<=h-m+1;s_row++)
	{
		for(int s_col=1;s_col<=w-m+1;s_col++)
		{
			for(int e_row=s_row+m-1;e_row<=h;e_row++)
			{
				for(int e_col=s_col+m-1;e_col<=w;e_col++)
				{
					Density	current;
					int		max_cnt,current_cnt;
					
					current.first = get_cnt_of_pixel(s_row,s_col,e_row,e_col);
					current.second = (e_row-s_row+1)*(e_col-s_col+1);
					
					max_cnt = max_density.first*current.second;
					current_cnt = current.first*max_density.second;
					
					if( (max_cnt<current_cnt) || 
						(max_cnt==current_cnt&&max_density.second<current.second) )
					{
						max_density = current;
					}
				}
			}
		}	
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		Density	d;
		
		input();
		get_table();
		find_max_density(d);
		
		cout<<"Data Set "<<k<<":\n"<<d.first<<'/'<<d.second<<"\n\n";
	}
	
	return	0;
}
