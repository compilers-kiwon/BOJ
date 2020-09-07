#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	struct	_NAME_INFO	Name;
struct	_NAME_INFO
{
	int	L,O,V,E;
};

int		get_score(int L,int O,int V,int E)
{
	return	((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;
}

Name	parse_name(string& name)
{
	Name	cnt;
	
	cnt.L =cnt.O = cnt.V = cnt.E = 0;
	
	for(int i=0;i<name.length();i++)
	{
		switch(name[i])
		{
			case	'L':
				cnt.L++;
				break;
			case	'O':
				cnt.O++;
				break;
			case	'V':
				cnt.V++;
				break;
			case	'E':
				cnt.E++;
				break;
			default:
				// do nothing
				break;
		}
	}

	return	cnt;
}

int		main(void)
{
	int		N,max_score;
	string	boy_name,girl_name,most_lovely_girl;
	Name	boy,girl;
	
	vector<string>	girls;
	
	cin>>boy_name;
	boy = parse_name(boy_name);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>girl_name;
		girls.push_back(girl_name);
	}
	
	sort(girls.begin(),girls.end());
	
	max_score = -1;
	
	for(int i=0;i<girls.size();i++)
	{
		int	tmp;
		
		girl = parse_name(girls[i]);
		tmp = get_score(boy.L+girl.L,boy.O+girl.O,boy.V+girl.V,boy.E+girl.E);
		
		if( max_score < tmp )
		{
			max_score = tmp;
			most_lovely_girl = girls[i];
		}
	}
	
	cout<<most_lovely_girl<<endl;
	
	return	0;
}
