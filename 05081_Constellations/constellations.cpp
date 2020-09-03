#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_NUM_OF_STARS	(500+1)
#define	INF					0x7FFFFFFF

typedef	pair<int,int>	Pos;

#define	get_distance(a,b,p)	(abs((p)[(a)].first-(p)[(b)].first)+abs((p)[(a)].second-(p)[(b)].second))

bool	input(int& num_of_stars,Pos* s)
{
	cin>>num_of_stars;
	
	if( num_of_stars == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=num_of_stars;i++)
	{
		cin>>s[i].first>>s[i].second;
	}
	
	return	true;
}

void	get_closest_star(int s,Pos* p,int num_of_stars,
						 vector<int>* closest,vector<int>& closest_distance)
{
	for(int i=s+1;i<=num_of_stars;i++)
	{
		int	d;
		
		d = get_distance(s,i,p);
		
		if( d <= closest_distance[s] )
		{
			if( d < closest_distance[s] )
			{
				closest_distance[s] = d;
				closest[s].clear();
			}
			closest[s].push_back(i);
		}
		
		if( d <= closest_distance[i] )
		{
			if( d < closest_distance[i] )
			{
				closest_distance[i] = d;
				closest[i].clear();
			}
			closest[i].push_back(s);
		}
	}
}

int		find_parent(int c,int* parent)
{
	int&	p = parent[c];
	
	if( p != c )
	{
		p = find_parent(p,parent);
	}
	
	return	p;
}

int		main(void)
{
	for(int sky=1;;sky++)
	{
		int	n;
		Pos	star[MAX_NUM_OF_STARS];
		
		if( input(n,star) == false )
		{
			break;
		}
		
		vector<int>	closest[MAX_NUM_OF_STARS];
		vector<int>	closest_distance(n+1,INF);
		
		for(int i=1;i<n;i++)
		{
			get_closest_star(i,star,n,closest,closest_distance);
		}
		
		int	parent[MAX_NUM_OF_STARS];
		
		for(int i=1;i<=n;i++)
		{
			parent[i] = i;
		}
		
		for(int current_star=1;current_star<=n;current_star++)
		{
			vector<int>&	adj_stars = closest[current_star];
			
			for(int i=0;i<adj_stars.size();i++)
			{
				int&	adj_star = adj_stars[i];
				int		p1,p2;
				
				p1 = find_parent(current_star,parent);
				p2 = find_parent(adj_star,parent);
				
				if( p1 != p2 )
				{
					if( p1 < p2 )
					{
						parent[p2] = p1;
					}
					else
					{
						parent[p1] = p2;
					}
				}
			}
		}
		
		vector<bool>	visited(n+1,false);
		int				cnt;
		
		cnt = 0;
		
		for(int i=1;i<=n;i++)
		{
			int	p;
			
			p = find_parent(i,parent);
			
			if( visited[p] == false )
			{
				visited[p] = true;
				cnt++;
			}
		}
		
		cout<<"Sky "<<sky<<" contains "<<cnt<<" constellations.\n";
	}
	
	return	0;
}
