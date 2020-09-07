#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	char2int(c)	((int)((c)-'A')+1)
#define	int2char(i)	((char)((i)-1+(int)'A'))

#define	MAX_NUM_OF_VILLAGE	(20+1)

typedef	struct	_ROAD_INFO	Road;
struct	_ROAD_INFO
{
	int	v1,v2,d;
};

typedef	pair<int,int>		Connected;	// first:to, second:distance
typedef	pair<int,string>	Path;		// first:distance, second:visited_villages

int				NV,NR,SV,DV,MAXDIST;
bool			visited[MAX_NUM_OF_VILLAGE];
vector<Path>	path_vec;
vector<int>		visited_villages;

bool	input(vector<Connected>* graph)
{
	cin>>NV;
	
	if( NV == -1 )
	{
		return	false;
	}
	
	cin>>NR;
	
	for(int i=1;i<=NR;i++)
	{
		int	C1,C2,DIST;
		
		cin>>C1>>C2>>DIST;
		
		graph[C1].push_back(make_pair(C2,DIST));
		graph[C2].push_back(make_pair(C1,DIST));
	}
	
	cin>>SV>>DV>>MAXDIST;
	
	return	true;
}

void	dfs(int current,int dst,vector<Connected>* graph,int current_dist)
{
	if( current == dst )
	{
		string	p;
		
		for(int i=0;i<visited_villages.size();i++)
		{
			p.push_back(int2char(visited_villages[i]));
		}
		
		path_vec.push_back(make_pair(current_dist,p));
		
		return;
	}
	
	vector<Connected>&	adj = graph[current];
	
	for(int i=0;i<adj.size();i++)
	{
		int&	adj_v = adj[i].first;
		int&	adj_d = adj[i].second;
		
		if( current_dist+adj_d<=MAXDIST && visited[adj_v]==false )
		{
			visited[adj_v] = true;
			visited_villages.push_back(adj_v);
			
			dfs(adj_v,dst,graph,current_dist+adj_d);
			
			visited_villages.pop_back();
			visited[adj_v] = false;
		}
	}
}

void	print_path(int c)
{
	cout<<"Case "<<c<<":\n";
	
	if( path_vec.size() == 0 )
	{
		cout<<" NO ACCEPTABLE TOURS\n\n";
		return;
	}
	
	for(int i=0;i<path_vec.size();i++)
	{
		int&	d = path_vec[i].first;
		string&	p = path_vec[i].second;
		
		cout<<' '<<d<<": ";
		
		for(int j=0;j<p.length();j++)
		{
			cout<<char2int(p[j])<<' ';
		}
		cout<<'\n';
	}
	
	cout<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int c=1;;c++)
	{
		vector<Connected>	graph[MAX_NUM_OF_VILLAGE];
		
		if( input(graph) == false )
		{
			break;
		}
		
		visited[SV] = true;
		visited_villages.push_back(SV);
		
		dfs(SV,DV,graph,0);
		
		visited_villages.pop_back();
		visited[SV] = false;
		
		sort(path_vec.begin(),path_vec.end());
		print_path(c);
		
		path_vec.clear();
	}
	
	return	0;
}
