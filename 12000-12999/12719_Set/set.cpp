#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	is_prime(n)	(visited[(n)]==false)

typedef	vector<int>	prime_factors;

int			A,B,P;
bool		visited[MAX_SIZE];
vector<int>	prime;

void	get_prime(void)
{
	for(int i=2;i<=MAX_SIZE;i++)
	{
		if( visited[i] == true )
		{
			continue;
		}
		
		for(int j=i+i;j<=MAX_SIZE;j+=i)
		{
			visited[j] = true;
		}
		
		prime.push_back(i);
	}
}

void	find_prime_factor(int n,vector<int>& prime_factors)
{
	vector<int>::iterator	it;
	
	it = lower_bound(prime.begin(),prime.end(),P);
	
	for(;it!=prime.end()&&(*it)<=B;it++)
	{
		if( n%(*it) == 0 )
		{
			prime_factors.push_back(*it);
		}
	}
}

bool	is_common_factor(const vector<int>& f1,const vector<int>& f2)
{
	bool	p[MAX_SIZE];
	
	fill(&p[2],&p[B+1],false);
	
	for(int i=0;i<f1.size();i++)
	{
		p[f1[i]] = true;
	}

	for(int i=0;i<f2.size();i++)
	{
		if( p[f2[i]] == true )
		{
			return	true;
		}
	}
	
	return	false;
}

int		find_parent(int n,int* parent)
{
	int&	ret = parent[n];
	
	if( ret != n )
	{
		ret = find_parent(ret,parent);
	}
	
	return	ret;
}

void	input(vector<int>* p_set)
{
	cin>>A>>B>>P;
	
	for(int i=A;i<=B;i++)
	{
		find_prime_factor(i,p_set[i]);
	}
}

int		get_num_of_sets(vector<int>* p_set)
{
	int		parent[MAX_SIZE],ret;
	bool	counted[MAX_SIZE];
	
	for(int i=A;i<=B;i++)
	{
		parent[i] = i;
	}
	
	for(int i=A;i<B;i++)
	{
		for(int j=i+1;j<=B;j++)
		{
			if( is_common_factor(p_set[i],p_set[j]) == false )
			{
				continue;
			}
			
			int	p1,p2;
			
			p1 = find_parent(i,parent);
			p2 = find_parent(j,parent);
			
			if( p1 == p2 )
			{
				continue;
			}
			
			parent[max(p1,p2)] = min(p1,p2);
		}
	}
	
	ret = 0;
	fill(&counted[A],&counted[B+1],false);
	
	for(int i=A;i<=B;i++)
	{
		int	p;
		
		if( counted[(p=find_parent(i,parent))] == false )
		{
			ret++;
			counted[p] = true;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	C;
	
	cin>>C;
	get_prime();
	
	for(int c=1;c<=C;c++)
	{
		vector<int>	prime_factor[MAX_SIZE];
		
		input(prime_factor);
		cout<<"Case #"<<c<<": "<<get_num_of_sets(prime_factor)<<'\n';
	}
	
	return	0;
}
