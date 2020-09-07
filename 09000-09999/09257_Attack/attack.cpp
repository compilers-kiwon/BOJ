#include	<iostream>

using namespace	std;

#define	MAX_SIZE_OF_NETWORK	20
#define	MAX_NUM_OF_BOMBS	100

typedef	long long int		int64;

int		n,m,k,c;
bool	connected[MAX_SIZE_OF_NETWORK][MAX_SIZE_OF_NETWORK];
int64	attackable[MAX_NUM_OF_BOMBS];
int64	purchase[MAX_SIZE_OF_NETWORK];

void	init(void)
{
	fill(attackable,attackable+MAX_NUM_OF_BOMBS,0LL);
	fill(purchase,purchase+MAX_SIZE_OF_NETWORK,0LL);
	
	for(int i=0;i<MAX_SIZE_OF_NETWORK;i++)
	{
		fill(&connected[i][0],&connected[i][MAX_SIZE_OF_NETWORK],false);
	}
}

void	get_data(int num,int64* ret)
{
	for(int i=0;i<num;i++)
	{
		int	size;
		
		cin>>size;
		
		for(int j=0;j<size;j++)
		{
			int	shift;
			
			cin>>shift;
			ret[i] |= 1LL<<shift;
		}
	}
}

void	input(void)
{
	cin>>n>>m>>k>>c;
	
	get_data(k,attackable);
	get_data(n,purchase);
	
	for(int i=0;i<c;i++)
	{
		int	p1,p2;
		
		cin>>p1>>p2;
		connected[p1-1][p2-1] = connected[p2-1][p1-1] = true;
	}
}

void	dfs(int64 current_items,int current_clique,int current_person,int& cnt)
{
	if( current_person == n )
	{
		return;
	}
	
	// 1. skip current_person
	dfs(current_items,current_clique,current_person+1,cnt);
	
	// 2. add current_person to clique
	bool	is_connected;
	
	is_connected = true;
	
	for(int i=0;i<n;i++)
	{
		if( (current_clique&(1<<i))!=0
			&& connected[i][current_person]==false )
		{
			is_connected = false;
			break;		
		}
	}
	
	if( is_connected == true )
	{
		int64	next_items;
		bool	found;
		
		found = false;
		next_items = current_items|purchase[current_person];
		
		for(int i=0;i<k;i++)
		{
			if( (next_items&attackable[i]) == attackable[i] )
			{
				found = true;
				break;
			}
		}
		
		if( found == true )
		{
			cnt++;
		}
		
		dfs(next_items,current_clique|(1<<current_person),current_person+1,cnt);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int d=1;d<=K;d++)
	{
		int	ret;
		
		init();
		input();
		
		ret = 0;
		dfs(0,0,0,ret);
		
		cout<<"Data Set "<<d<<":\n"<<ret<<"\n\n";
	}
	
	return	0;
}
