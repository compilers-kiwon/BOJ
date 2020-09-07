#include	<iostream>
#include	<vector>
#include	<map>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	150

typedef	pair<int,int>		Rectangle;
typedef	vector<Rectangle>	RectList;

map<int,RectList>	table;

void	build_table(void)
{
	for(int h=1;h<150;h++)
	{
		int	pow_h = h*h;
		
		for(int w=h+1;w<=150;w++)
		{
			int	diagonal;
			
			diagonal = pow_h+w*w;
			table[diagonal].push_back(make_pair(h,w)); 
		}
	}
	
	for(int i=1;i<=150*150;i++)
	{
		if( table[i].size() != 0 )
		{
			sort(table[i].begin(),table[i].end());
		}
	}
}

int		main(void)
{
	build_table();
	
	while(1)
	{
		int			h,w,d;
		Rectangle	r;
		
		cin>>h>>w;
		
		if( h == 0 && w == 0 )
		{
			break;
		}
		
		d = h*h+w*w;
		
		if( table[d].back().first != h )
		{
			int			i;
			Rectangle	input;
			
			for(i=0,input=make_pair(h,w);i<table[d].size();i++)
			{
				if( table[d][i] == input )
				{
					break;
				}
			}
			
			r =	table[d][i+1]; 
		}
		else
		{
			for(int i=d+1;;i++)
			{
				if( table[i].size() != 0 )
				{
					r = table[i][0];
					break;
				}
			}
		}
		
		cout<<r.first<<' '<<r.second<<'\n';
	}
	
	return	0;
}
