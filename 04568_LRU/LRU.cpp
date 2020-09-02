#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE		26
#define	INF				0x7FFFFFFF
#define	get_index(c)	((int)((c)-'A'))

typedef	pair<int,char>	Cache;

int		get_victim(string& current_cache,int* time_to_be_used)
{
	int	ret,t;
	
	t = INF;
	
	for(int i=0;i<current_cache.length();i++)
	{
		int	idx;
		
		idx = get_index(current_cache[i]);
		
		if( time_to_be_used[idx] < t )
		{
			t = time_to_be_used[idx];
			ret = i;
		}
	}
	
	return	ret;
}

void	print_cache(string& current_cache,int* time_to_be_used)
{
	vector<Cache>	c;
	
	for(int i=0;i<current_cache.length();i++)
	{
		char&	p = current_cache[i];
		int		idx;
		
		idx = get_index(p);
		c.push_back(make_pair(time_to_be_used[idx],p));
	}
	
	sort(c.begin(),c.end());
	
	for(int i=0;i<c.size();i++)
	{
		cout<<c[i].second;
	}
	cout<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int s=1;;s++)
	{
		int		N,time_to_be_used[MAX_SIZE];
		bool	is_cached[MAX_SIZE];
		string	data,cache;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		cin>>data;
		cout<<"Simulation "<<s<<'\n';
		
		fill(&is_cached[0],&is_cached[MAX_SIZE],false);
		fill(&time_to_be_used[0],&time_to_be_used[MAX_SIZE],-1);
		
		for(int i=0;i<data.length();i++)
		{
			char&	p = data[i];
			int		idx,v;
			
			if( p == '!' )
			{
				print_cache(cache,time_to_be_used);
				continue;
			}
			
			idx = get_index(p);
			
			if( is_cached[idx] == true )
			{
				time_to_be_used[idx] = i;
				continue;
			}
			
			if( cache.length() != N )
			{
				cache.push_back(p);
				time_to_be_used[idx] = i;
				is_cached[idx] = true;
				
				continue;
			}
			
			v = get_victim(cache,time_to_be_used);
			
			char&	victim = cache[v];
			
			time_to_be_used[get_index(victim)] = -1;
			is_cached[get_index(victim)] = false;
			
			cache[v] = p;
			time_to_be_used[idx] = i;
			is_cached[idx] = true;
		}
	}
	
	return	0;
}
