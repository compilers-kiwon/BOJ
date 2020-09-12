#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))
#define	INF			1000000

typedef	pair<int,string>	MP;

void	parse(string& str,int& id,string& name)
{
	int	i;
	
	id = 0;
	
	for(i=0;str[i]!=' ';i++)
	{
		id = id*10+char2int(str[i]);
	}
	
	for(++i;i<str.length();i++)
	{
		name.push_back(str[i]);
	}
}

void	find_best_and_worst(map<int,MP>& table,int& best_score,int& worst_score,
							vector<string>& best_name,vector<string>& worst_name)
{
	map<int,MP>::iterator	it;
	
	best_score = -INF;
	worst_score = INF;
	
	for(it=table.begin();it!=table.end();it++)
	{
		int&	score = it->second.first;
		string&	name = it->second.second;
		
		if( score >= best_score )
		{
			if( score > best_score )
			{
				best_score = score;
				best_name.clear();
			}
			best_name.push_back(name);
		}
		
		if( score <= worst_score )
		{
			if( score < worst_score )
			{
				worst_score = score;
				worst_name.clear();
			}
			worst_name.push_back(name);
		}
	}
}

void	give_points(map<int,MP>& table)
{
	int	A;
	
	cin>>A;
	
	for(int i=1;i<=A;i++)
	{
		int		id,p;
		char	code;
		
		cin>>id>>code;
		
		switch(code)
		{
			case	'S':
				p = 10;
				break;
			case	'Q':
				p = 5;
				break;
			case	'A':
				p = 7;
				break;
			case	'L':
				p = -8;
				break;
			case	'F':
				p = 4;
				break;
			case	'D':
				p = -5;
				break;
			case	'E':
				p = -10;
				break;
			default:
				p = 0;
				break;
		}
		
		table[id].first += p;
	}
}

void	print(int s,vector<string>& n)
{
	cout<<s;
	
	for(int i=0;i<n.size();i++)
	{
		cout<<' '<<n[i];
	}
	cout<<'\n';
}

int		main(void)
{
	int			N;
	map<int,MP>	mp;
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		int		id;
		string	input,name;
		
		getline(cin,input);
		parse(input,id,name);
		
		mp[id] = make_pair(0,name);
	}
	
	give_points(mp);
	
	int				best_score,worst_score;
	vector<string>	best_mp,worst_mp;
	
	find_best_and_worst(mp,best_score,worst_score,best_mp,worst_mp);
	
	print(best_score,best_mp);
	print(worst_score,worst_mp);
	
	return	0;
}
