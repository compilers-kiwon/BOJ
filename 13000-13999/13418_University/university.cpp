#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	UPHILL		0
#define	DOWNHILL	1
#define	MAX_HILL	2

#define	get_next_hill(h)	(((h)+1)%MAX_HILL)

typedef	pair<int,int>	Path;

int				N,M,parent[MAX_SIZE];
vector<Path>	path[MAX_HILL];

int		find_parent(int n)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret);
	}
	
	return	ret;
}

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M+1;i++)
	{
		int	A,B,C;
		
		cin>>A>>B>>C;
		path[C].push_back(make_pair(A,B));
	}
}

void	init_parent(void)
{
	for(int i=1;i<=N;i++)
	{
		parent[i] = i;
	}
}

int		get_fatigue(int hill)
{
	int	cnt;
	
	cnt = 0;
	init_parent();
	
	for(int h=0;h<MAX_HILL;h++,hill=get_next_hill(hill))
	{
		for(int i=0;i<path[hill].size();i++)
		{
			int&	n1 = path[hill][i].first;
			int&	n2 = path[hill][i].second;
			int		p1,p2;
			
			p1 = find_parent(n1);
			p2 = find_parent(n2);
			
			if( p1 != p2 )
			{
				int	big,small;
				
				big = max(p1,p2);
				small = min(p1,p2);
				parent[big] = small;
				
				if( hill == UPHILL )
				{
					cnt++;
				}
			}
		}
	}
	
	return	(cnt*cnt);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	worst,best;
	
	worst = get_fatigue(UPHILL);
	best = get_fatigue(DOWNHILL);
	
	cout<<worst-best<<'\n';
	
	return	0;
}
