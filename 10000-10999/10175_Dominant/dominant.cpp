#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	Bobcat			'B'
#define	Coyote			'C'
#define	Mountain_Lion	'M'
#define	Wolf			'W'

typedef	struct	_ANIMAL_INFO	Animal;
struct	_ANIMAL_INFO
{
	string	name;
	int		value,total_value;	
};

map<char,Animal>	table;

void	init(void)
{
	table[Bobcat].name = "Bobcat";
	table[Bobcat].value = 2;
	
	table[Coyote].name = "Coyote";
	table[Coyote].value = 1;
	
	table[Mountain_Lion].name = "Mountain Lion";
	table[Mountain_Lion].value = 4;
	
	table[Wolf].name = "Wolf";
	table[Wolf].value = 3;
}

void	parse_cnt(string& cnt)
{
	for(int i=0;i<cnt.length();i++)
	{
		char&	c = cnt[i];
		
		table[c].total_value += table[c].value;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	int	n;
	
	cin>>n;
	
	for(;n>0;n--)
	{
		string						location,cnt;
		map<char,Animal>::iterator	it;
		
		for(it=table.begin();it!=table.end();it++)
		{
			it->second.total_value = 0;
		}
		
		cin>>location>>cnt;
		
		parse_cnt(cnt);
		
		int		max_value,num_of_max_value;
		string	animal_of_max_value;
		
		max_value = 0;
		num_of_max_value = 1;
		
		for(it=table.begin();it!=table.end();it++)
		{
			if( it->second.total_value > max_value )
			{
				max_value = it->second.total_value;
				num_of_max_value = 1;
				animal_of_max_value = it->second.name;
			}
			else if( it->second.total_value == max_value )
			{
				num_of_max_value++;
			}
		}
		
		if( num_of_max_value == 1 )
		{
			cout<<location<<": The "<<animal_of_max_value<<" is the dominant species\n";
		}
		else
		{
			cout<<location<<": There is no dominant species\n";
		}
	}
	
	return	0;
}
