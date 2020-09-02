#include	<iostream>
#include	<cmath>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100+1)

typedef	pair<double,double>	Pos;		// first:x,second:y
typedef	pair<int,int>		Path;		// first:star1,second:star2
typedef	pair<double,Path>	Connected;	// first:distance,second:Path

int	n,parent[MAX_SIZE];
Pos	star[MAX_SIZE];

void	input(void)
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		double	x,y;
		
		scanf("%lf %lf",&star[i].first,&star[i].second);
		parent[i] = i;
	}
}

void	get_distance(vector<Connected>&	connected)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double	dx,dy;
			
			dx = star[i].first-star[j].first;
			dy = star[i].second-star[j].second;
			
			connected.push_back(make_pair(sqrt(dx*dx+dy*dy),make_pair(i,j)));
		}
	}
}

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret);
	}
	
	return	ret;
}

void	merge(const int& p1,const int& p2)
{
	int	big,small;
	
	big = max(p1,p2);
	small = min(p1,p2);
	
	parent[big] = small;
}

int		main(void)
{
	vector<Connected>	connected;
	
	input();
	get_distance(connected);
	
	sort(connected.begin(),connected.end());
	
	double	sum;
	int		i,num_of_selected;
	
	for(i=num_of_selected=0,sum=0.0;num_of_selected!=n-1;i++)
	{
		int&	s1 = connected[i].second.first;
		int&	s2 = connected[i].second.second;
		double&	d = connected[i].first;
			
		int	p1,p2;
		
		p1 = find_parent(s1);
		p2 = find_parent(s2);
		
		if( p1 != p2 )
		{
			merge(p1,p2);
			num_of_selected++;
			sum += d;
		}
	}
	
	printf("%.02f\n",sum);
	
	return	0;
}
