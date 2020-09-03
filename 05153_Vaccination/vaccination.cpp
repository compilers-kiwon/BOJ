#include	<iostream>
#include	<vector>
#include	<queue>
#include	<string>

using namespace	std;

#define	MAX_SIZE_OF_NETWORK	(30+1)
#define	char2int(c)			((int)((c)-'0'))

int			n,D;
vector<int>	connected[MAX_SIZE_OF_NETWORK];
bool		is_vaccinated[MAX_SIZE_OF_NETWORK];

int		bfs(int s,bool* visited)
{
	int			ret;
	queue<int>	infected;
	
	ret = 1;
	visited[s] = true;
	infected.push(s);
	
	for(;!infected.empty();)
	{
		int	infected_person;
		
		infected_person = infected.front();
		infected.pop();
		
		vector<int>&	adj = connected[infected_person];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	p = adj[i];
			
			if( is_vaccinated[p]==false && visited[p]==false )
			{
				ret++;
				visited[p] = true;
				infected.push(p);
			}
		}
	}
	
	return	ret;
}

int		get_max_num_of_infected(int max_value)
{
	int		ret;
	bool	visited[MAX_SIZE_OF_NETWORK];
	
	ret = 0;
	fill(&visited[1],&visited[n+1],false);
	
	for(int i=1;i<=n;i++)
	{
		if( is_vaccinated[i]==false && visited[i]==false )
		{
			ret = max(ret,bfs(i,visited));
			
			if( ret > max_value )
			{
				break;
			}
		}
	}
	
	return	ret;
}

void	vaccinate_network(int person_idx,int num_of_vaccination,int& min_num_of_infection)
{
	if( num_of_vaccination == D )
	{
		min_num_of_infection = min(min_num_of_infection,
									get_max_num_of_infected(min_num_of_infection));
		return;
	}
	
	for(int p=person_idx;p<=n;p++)
	{
		is_vaccinated[p] = true;
		vaccinate_network(p+1,num_of_vaccination+1,min_num_of_infection);
		is_vaccinated[p] = false;
	}
}

void	init(void)
{
	for(int i=1;i<=MAX_SIZE_OF_NETWORK;i++)
	{
		connected[i].clear();
		is_vaccinated[i] = false;
	}
}

void	parse(string& str,int person_idx)
{
	int	num;
	
	num = 0;
	str.push_back(' ');;
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			if( num != 0 )
			{
				connected[person_idx].push_back(num);
				num = 0;
			}
		}
		else
		{
			num = num*10+char2int(str[i]);
		}
	}
}

void	input(void)
{
	cin>>n>>D;getchar();getchar();
	
	for(int i=1;i<=n;i++)
	{
		string	str;
		
		getline(cin,str);
		parse(str,i);
	}
}

int		main(void)
{
	int	K;
	
	cin>>K;getchar();
	
	for(int k=1;k<=K;k++)
	{
		init();
		input();
		
		int	min_num_of_infection;
		
		min_num_of_infection = n;
		vaccinate_network(1,0,min_num_of_infection);
		
		cout<<"Data Set "<<k<<":\n"<<min_num_of_infection<<"\n\n";
	}
	
	return	0;
}
