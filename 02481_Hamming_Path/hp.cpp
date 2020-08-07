#include	<iostream>
#include	<string>
#include	<queue>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_NUM_OF_CODE		(100000+1)
#define	MAX_NUM_OF_QUERY	(50+1)
#define	MAX_CODE_LEN		30
#define	NONE				0

int				N,K,M;
int				q[MAX_NUM_OF_QUERY];
int				parent[MAX_NUM_OF_CODE];
bool			visited[MAX_NUM_OF_CODE];
vector<int>		connected[MAX_NUM_OF_CODE];
map<int,int>	code;	// code[value] = index

int		str2int(string& bin)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<K;i++)
	{
		ret = (ret<<1)+(int)(bin[i]-'0');
	}
	
	return	ret;
}

void	input(void)
{
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		string	s;
			
		cin>>s;
		code[str2int(s)] = i;
	}
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		cin>>q[i];
	}
}

void	build_graph(void)
{
	map<int,int>::iterator	it;
	
	for(it=code.begin();it!=code.end();it++)
	{
		int	current_value,current_index;
		
		current_value = it->first;
		current_index = it->second;
		
		for(int i=0;i<K;i++)
		{
			int	adj_value,adj_index;
			
			adj_value = current_value^(1<<i);
			
			if( code.count(adj_value) )
			{
				adj_index = code[adj_value];
				connected[current_index].push_back(adj_index);
			}
		}
	}
}

void	find_hamming_path(void)
{
	queue<int>	q;
	
	q.push(1);
	visited[1] = true;
		
	for(;!q.empty();)
	{
		int	current_index;
		
		current_index = q.front();
		q.pop();
		
		vector<int>&	adj = connected[current_index];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	adj_index = adj[i];
			
			if( visited[adj_index] == false )
			{
				visited[adj_index] = true;
				parent[adj_index] = current_index;
				
				q.push(adj_index);
			}
		}
	}
}

void	print_path(int n)
{
	if( visited[n] == false )
	{
		cout<<"-1\n";
	}
	else
	{
		vector<int>	p;
		
		for(int i=n;i!=NONE;i=parent[i])
		{
			p.push_back(i);
		}
		
		for(int i=p.size()-1;i>=0;i--)
		{
			cout<<p[i]<<' ';
		}
		cout<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	build_graph();
	find_hamming_path();
	
	for(int i=1;i<=M;i++)
	{
		print_path(q[i]);
	}
	
	return	0;
}
