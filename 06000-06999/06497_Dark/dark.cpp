#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	200000

typedef	pair<int,int>	Path;		// first:h1,second:h2
typedef	pair<int,Path>	Connected;	// first:-cost,second:Path

int			parent[MAX_SIZE];
Connected	connected[MAX_SIZE];

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

bool	input(int& num_of_house,int& num_of_path,int& total_cost)
{
	cin>>num_of_house>>num_of_path;
	
	if( num_of_house==0 && num_of_path==0 )
	{
		return	false;
	}
	
	total_cost = 0;
	
	for(int i=0;i<num_of_path;i++)
	{
		int&	x = connected[i].second.first;
		int&	y = connected[i].second.second;
		int&	z = connected[i].first;
		
		cin>>x>>y>>z;
		total_cost += z;
		
		parent[x] = x;
		parent[y] = y;
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	m,n,num_of_selected_path;
		int	total_cost,used_cost;
		
		if( input(m,n,total_cost) == false )
		{
			break;
		}
		
		sort(&connected[0],&connected[n]);
		num_of_selected_path = used_cost = 0;
		
		for(int i=0;num_of_selected_path!=m-1;i++)
		{
			int&	h1 = connected[i].second.first;
			int&	h2 = connected[i].second.second;
			int&	cost = connected[i].first;
			
			int	p1,p2;
			
			p1 = find_parent(h1);
			p2 = find_parent(h2);
			
			if( p1 != p2 )
			{
				merge(p1,p2);
				num_of_selected_path++;
				used_cost += cost;
			}
		}
		
		cout<<total_cost-used_cost<<'\n';
	}
	
	return	0;
}
