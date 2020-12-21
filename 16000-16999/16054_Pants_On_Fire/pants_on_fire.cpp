#include	<iostream>
#include	<string>
#include	<vector>
#include	<queue>
#include	<map>

using namespace	std;

int	n,m;

typedef	vector<string>	Worse;

map<string,Worse>	NYT;

void	get_country_name(string& str,string& worse,string& better)
{
	string			tmp;
	vector<string>	w;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			w.push_back(tmp);
			tmp.clear();
		}
		else
		{
			tmp.push_back(str[i]);
		}
	}
	
	worse = w.front();
	better = w.back();
}

void	get_true_statements(void)
{
	for(int i=1;i<=n;i++)
	{
		string	statement,a,b;
		
		getline(cin,statement);
		get_country_name(statement,a,b);
		
		NYT[b].push_back(a);
	}
}

bool	search_country(const string& from,const string& to)
{
	queue<string>		q;
	map<string,bool>	visited;
	
	q.push(from);
	visited[from] = true;
	
	for(;!q.empty();)
	{
		string	current;
		
		current = q.front();
		q.pop();
		
		if( current == to )
		{
			return	true;
		}
		
		Worse&	adj = NYT[current];
		
		for(int i=0;i<adj.size();i++)
		{
			if( visited[adj[i]] == false )
			{
				q.push(adj[i]);
				visited[adj[i]] = true;
			}
		}
	}
	
	return	false;
}

void	classify_statement(void)
{
	string	statement,w,b;
	
	getline(cin,statement);
	get_country_name(statement,w,b);
	
	bool	w_is_better_than_b,b_is_better_than_w;
	
	w_is_better_than_b = search_country(w,b);
	b_is_better_than_w = search_country(b,w);
	
	if( w_is_better_than_b==false && b_is_better_than_w==false )
	{
		cout<<"Pants on Fire\n";
	}
	else
	{
		if( b_is_better_than_w == true )
		{
			cout<<"Fact\n";
		}
		else
		{
			cout<<"Alternative Fact\n";
		}
	}
}

int		main(void)
{
	cin>>n>>m;getchar();
	get_true_statements();
	
	for(int i=1;i<=m;i++)
	{
		classify_statement();
	}
	
	return	0;
}
