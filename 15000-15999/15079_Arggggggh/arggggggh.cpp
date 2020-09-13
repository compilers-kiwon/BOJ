#include	<iostream>
#include	<cmath>
#include	<map>

using namespace	std;

typedef	pair<double,double>	Adj;

double	get_delta(string& dir,double d)
{
	double	ret;
	
	if( dir.length() == 2 )
	{
		ret = d/sqrt(2);	
	}
	else
	{
		ret = d;	
	}
	
	return	ret;	
}

void	init(map<string,Adj>& t)
{
	t["SW"] = make_pair(-1.0,-1.0);
	t["S"] = make_pair(-1.0,0.0);
	t["SE"] = make_pair(-1.0,1.0);
	t["E"] = make_pair(0.0,1.0);
	t["NE"] = make_pair(1.0,1.0);
	t["N"] = make_pair(1.0,0.0);
	t["NW"] = make_pair(1.0,-1.0);
	t["W"] = make_pair(0.0,-1.0);
}

int	main(void)
{
	int				n;
	double			x,y;
	map<string,Adj>	table;
	
	init(table);
	cin>>n>>x>>y;
	
	for(int i=1;i<n;i++)
	{
		string	dir;
		double	d,delta;
		
		cin>>dir>>d;
		delta = get_delta(dir,d);
		
		y += delta*table[dir].first;
		x += delta*table[dir].second;
	}
	
	printf("%.8f %.8f\n",x,y);
	
	return	0;
}
