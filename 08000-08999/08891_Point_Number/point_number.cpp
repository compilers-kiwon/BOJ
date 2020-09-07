#include	<iostream>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Range;

#define	MAX_NUM	200000

void	init_table(vector<Range>& table)
{
	Range	r;
	int		inc;
	
	r = make_pair(0,0);
	table.push_back(r);
	
	inc = 0;
	
	for(int from=1,to;from<MAX_NUM;from+=++inc)
	{
		to=from+inc;
		r = make_pair(from,to);
		table.push_back(r);
	}
}

void	convert(int& n,int& x,int& y,vector<Range>& table)
{
	int	i,diff;
	
	for(i=1;i<table.size();i++)
	{
		if( table[i].first<=n && n<=table[i].second )
		{
			break;
		}
	}
	diff = n-table[i].first;
	
	y = i-diff;
	x = diff+1;
}

int		main(void)
{
	vector<Range>	t;
	
	init_table(t);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n1,n2,n3;
		int	n1_x,n1_y,n2_x,n2_y,n3_x,n3_y;
		
		cin>>n1>>n2;
		
		convert(n1,n1_x,n1_y,t);
		convert(n2,n2_x,n2_y,t);
				
		n3_x = n1_x+n2_x;
		n3_y = n1_y+n2_y;
		
		int	x_diff,y,from;
		
		x_diff = n3_x-1;
		y = n3_y+x_diff;
		from = t[y].first;
		n3 = from+x_diff;
		
		cout<<n3<<endl;
		
		T--;
	}
	return	0;
}
