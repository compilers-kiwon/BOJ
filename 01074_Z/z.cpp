#include	<iostream>
#include	<cmath>

using namespace	std;

typedef	pair<int,int>		Range;
typedef	pair<Range,Range>	Cell;	// first:row,second:col

int	count(Cell cell,int r,int c,int cnt,int n)
{
	cout<<cell.first.first<<' '<<cell.first.second<<endl;
	cout<<cell.second.first<<' '<<cell.second.second<<endl;
	if( n == 0 )
	{
		return	cnt;
	}
	
	int		r_from,r_to,c_from,c_to,len;
	Cell	new_cell;
	Range	r_range,c_range;
	int		d;
	
	r_from = cell.first.first;
	r_to = cell.first.second;
	
	c_from = cell.second.first;
	c_to = cell.second.second;
	
	len = (r_to-r_from+1)/2;
	
	if( r<(r_from+len) )
	{
		r_range = make_pair(r_from,r_from+len-1);
		d = 0;
	}
	else
	{
		r_range = make_pair(r_from+len,r_to);
		d = 2;
	}
	
	if( c<(c_from+len) )
	{
		c_range = make_pair(c_from,c_from+len-1);
		d += 0;
	}
	else
	{
		c_range = make_pair(c_from+len,c_to);
		d += 1;
	}
	
	new_cell = make_pair(r_range,c_range);

	return	count(new_cell,r,c,cnt+d*len*len,n-1);	
}

int	main(void)
{
	int		N,r,c,len;
	Range	init;
	
	cin>>N>>r>>c;
	len = pow(2,N);
	init = make_pair(0,len-1);
	
	cout<<count(make_pair(init,init),r,c,0,N);
	
	return	0;	
}
