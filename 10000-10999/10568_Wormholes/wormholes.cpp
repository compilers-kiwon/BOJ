#include	<iostream>
#include	<string>
#include	<map>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(60+1)

typedef	pair<int,int>	Wormhole;	// first:entry, second:exit
typedef	long long int	int64;

typedef	struct	_PLANET_INFO	Planet;
struct	_PLANET_INFO
{
	int64	x,y,z;
};

double	get_distance(const Planet& p1,const Planet& p2)
{
	int64	dx,dy,dz;
	
	dx = ((p1).x-(p2).x)*((p1).x-(p2).x);
	dy = ((p1).y-(p2).y)*((p1).y-(p2).y);
	dz = ((p1).z-(p2).z)*((p1).z-(p2).z);
	
	return	sqrt(dx+dy+dz);
}

void	build_distance_table(double t[][MAX_SIZE],const int& num_of_planet)
{
	for(int k=1;k<=num_of_planet;k++)
	{
		for(int i=1;i<=num_of_planet;i++)
		{
			for(int j=1;j<=num_of_planet;j++)
			{
				if( t[i][j] > t[i][k]+t[k][j] )
				{
					t[i][j] = t[i][k]+t[k][j];
				}
			}
		}
	}
}

void	init_distance_table(const vector<Wormhole>& w,const Planet* p,
							double t[][MAX_SIZE],const int& num_of_planet)
{
	for(int i=1;i<=num_of_planet;i++)
	{
		t[i][i] = 0.0;
		
		for(int j=i+1;j<=num_of_planet;j++)
		{
			t[i][j] = t[j][i] = get_distance(p[i],p[j]);
		}
	}
	
	for(int i=0;i<w.size();i++)
	{
		t[w[i].first][w[i].second] = 0.0;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int					p,w,q;
		map<string,int>		planet_idx;
		vector<Wormhole>	wormholes;
		double				distance_table[MAX_SIZE][MAX_SIZE];
		Planet				planet[MAX_SIZE];
		
		cin>>p;
		
		for(int i=1;i<=p;i++)
		{
			string	str;
			
			cin>>str>>planet[i].x>>planet[i].y>>planet[i].z;
			planet_idx[str] = i;
		}
		
		cin>>w;
		
		for(int i=1;i<=w;i++)
		{
			string	p1,p2;
			
			cin>>p1>>p2;
			wormholes.push_back(make_pair(planet_idx[p1],planet_idx[p2]));
		}
		
		init_distance_table(wormholes,planet,distance_table,p);
		build_distance_table(distance_table,p);
		
		cin>>q;
		cout<<"Case "<<t<<":\n";
		
		for(int i=1;i<=q;i++)
		{
			string	p1,p2;
			double	d;
			
			cin>>p1>>p2;
			d = distance_table[planet_idx[p1]][planet_idx[p2]];
			
			cout<<"The distance from "<<p1<<" to "<<p2<<" is "<<(int64)round(d)<<" parsecs.\n";
		}
	}
	
	return	0;
}
