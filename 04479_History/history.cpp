#include	<iostream>
#include	<set>
#include	<map>
#include	<string>

using namespace	std;

typedef	pair<double,string>	Sith;
typedef	set<Sith>			Event;
			
void	input(map<int,Event>& e)
{
	int	n;
	
	cin>>n;getchar();
	
	for(int i=1;i<=n;i++)
	{
		string	name;
		double	d1,d2;
		
		getline(cin,name);
		cin>>d1>>d2;getchar();
		
		e[(int)d1].insert(make_pair(d1,name));
		
		if( (int)d1 != (int)d2 )
		{
			for(int y=((int)d1)+1;y<(int)d2;y++)
			{
				e[y].insert(make_pair((double)y,name));
			}
			e[(int)d2].insert(make_pair(d2,name));
		}
	}
}

void	do_query(map<int,Event>& e)
{
	int	c;
	
	cin>>c;
	
	for(int i=1;i<=c;i++)
	{
		int		y;
		string	output;
		
		cin>>y;
		
		Event::iterator	it;
				
		for(it=e[y].begin();it!=e[y].end();it++)
		{
			output += it->second+", ";
		}
		
		if( output.length() != 0 )
		{
			output.erase(output.length()-2,2);
			cout<<"Galactic year "<<y<<": "<<output<<'\n';
		}
		else
		{
			cout<<"Galactic year "<<y<<": None\n";
		}
	}
}

int		main(void)
{
	map<int,Event>	e;
	
	input(e);
	do_query(e);
	
	return	0;
}
