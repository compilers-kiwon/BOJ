#include	<iostream>
#include	<list>
#include	<algorithm>
#include	<string>

using namespace	std;

typedef	pair<int,int>	Post_It;

list<Post_It>	p;

#define	time	first
#define	table	second

bool	is_faster(const Post_It& p1,const Post_It& p2)
{
	bool	result;
	
	if( p1.time < p2.time )
	{
		result = true;
	}
	else if( p1.time > p2.time )
	{
		result = false;
	}
	else
	{
		if( p1.table < p2.table )
		{
			result = true;
		}
		else
		{
			result = false;
		}
	}
	
	return	result;
}

void	complete_order(int table)
{
	list<Post_It>::iterator	pi;
	
	for(pi=p.begin();pi!=p.end();pi++)
	{
		if( pi->table == table )
		{
			p.erase(pi);
			break;
		}
	}
}

void	print_post_it(void)
{
	if( p.empty() == true )
	{
		cout<<"sleep\n";
		return;
	}
	
	list<Post_It>::iterator	pi;
	
	for(pi=p.begin();pi!=p.end();pi++)
	{
		cout<<pi->table<<' ';
	}
	cout<<endl;
}

int		main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		string	instruction;
		int		n,t;
		
		cin>>instruction;
		
		if( instruction == "order" )
		{
			cin>>n>>t;
			p.push_back(make_pair(t,n));
		}
		else if( instruction == "sort" )
		{
			p.sort(is_faster);
		}
		else
		{
			cin>>n;
			complete_order(n);
		}
		print_post_it();
	}
	
	return	0;
}
