#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_CITIES	(100+1)
#define	MAX_NUM_OF_ROADS	(100+1)

typedef	pair<int,int>	Path;
typedef	pair<int,Path>	Road;

int		V,E,parent[MAX_NUM_OF_CITIES];
Road	road[MAX_NUM_OF_ROADS];

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret);
	}
	
	return	ret;
}

void	merge_tree(int p1,int p2)
{
	int	big,small;
	
	big = max(p1,p2);
	small = min(p1,p2);
	
	parent[big] = small;
}

void	input(void)
{
	cin>>V>>E;
	
	for(int i=1;i<=E;i++)
	{
		int&	a = road[i].second.first;
		int&	b = road[i].second.second;
		int&	d = road[i].first;
		
		cin>>a>>b>>d;
	}
	
	sort(&road[1],&road[E+1]);
}

int		build_spanning_tree(int skipped_city)
{
	int	ret;
	
	ret = 0;
	
	for(int i=1;i<=E;i++)
	{
		int&	a = road[i].second.first;
		int&	b = road[i].second.second;
		int&	d = road[i].first;
		
		if( a==skipped_city || b==skipped_city )
		{
			continue;
		}
		
		int	a_parent,b_parent;
		
		a_parent = find_parent(a);
		b_parent = find_parent(b);
		
		if( a_parent == b_parent )
		{
			continue;
		}
		
		ret += d;
		merge_tree(a_parent,b_parent);
	}
	
	return	ret;
}

bool	can_visit_each_city(int skipped_city)
{
	bool	ret;
	
	ret = true;

	for(int i=1;i<=V;i++)
	{
		if( i == skipped_city )
		{
			continue;
		}
		
		if( find_parent(i) != 1 )
		{
			ret = false;
			break;
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
		input();
		
		int	min_distance;
		
		min_distance = 0x7FFFFFFF;
		
		for(int i=2;i<=V;i++)
		{
			int	total_distance;
			
			for(int j=1;j<=V;j++)
			{
				parent[j] = j;
			}
			
			total_distance = build_spanning_tree(i);
			
			if( can_visit_each_city(i) == true )
			{
				min_distance = min(min_distance,total_distance);
			}
		}
		
		cout<<"Data Set "<<k<<":\n"<<min_distance*2<<"\n\n";
	}
	
	return	0;
}
