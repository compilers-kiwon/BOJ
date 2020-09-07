#include	<iostream>
#include	<vector>

using namespace	std;

#define	INF					10000000
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// firsst:x,second:y

void	input(vector<Pos>& station,vector<int>& visit)
{
	int	n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		Pos	p;
		
		cin>>p.first>>p.second;
		station.push_back(p);
	}
	
	for(int i=1;i<=m;i++)
	{
		int	v;
		
		cin>>v;
		visit.push_back(v-1);
	}
}

void	find_rectangle(int& min_x,int& min_y,
					   int& max_x,int& max_y,
					   vector<Pos>& station,
					   vector<int>& visit)
{
	min_x = min_y = INF;
	max_x = max_y = -INF;
	
	for(int i=0;i<visit.size();i++)
	{
		int&	x = station[visit[i]].first;
		int&	y = station[visit[i]].second;
		
		min_x = min(min_x,x);
		max_x = max(max_x,x);
		
		min_y = min(min_y,y);
		max_y = max(max_y,y);
	}
}

int		count_inner_stations(int& min_x,int& min_y,
					   		 int& max_x,int& max_y,
					   		 vector<Pos>& station)
{
	int	ret,i;
	
	for(i=ret=0;i<station.size();i++)
	{
		int&	x = station[i].first;
		int&	y = station[i].second;
		
		if( IN_RANGE(min_x,x,max_x) && IN_RANGE(min_y,y,max_y) )
		{
			ret++;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		vector<Pos>	station;
		vector<int>	visit;
		int			left,right,bottom,top;
		
		input(station,visit);
		find_rectangle(left,bottom,right,top,station,visit);
		
		cout<<"Data Set "<<k<<":\n"<<
			count_inner_stations(left,bottom,right,top,station)<<"\n\n";
	}
	
	return	0;
}
