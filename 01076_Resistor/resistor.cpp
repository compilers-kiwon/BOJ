#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

typedef	unsigned long long	uint64;
typedef	pair<uint64,uint64>	value;

map<string,value>	r_table;

void	init_r_table(void)
{
	r_table["black"] = make_pair(0,1);
	r_table["brown"] = make_pair(1,10);
	r_table["red"] = make_pair(2,100);
	r_table["orange"] = make_pair(3,1000);
	r_table["yellow"] = make_pair(4,10000);
	r_table["green"] = make_pair(5,100000);
	r_table["blue"] = make_pair(6,1000000);
	r_table["violet"] = make_pair(7,10000000);
	r_table["grey"] = make_pair(8,100000000);
	r_table["white"] = make_pair(9,100000000);
}

int		main(void)
{
	string	r1,r2,r3;
	
	init_r_table();
	
	cin>>r1>>r2>>r3;
	
	uint64	resistor;
	
	resistor = r_table[r1].first*10+r_table[r2].first;
	resistor *= r_table[r3].second;
	
	cout<<resistor<<endl;
	
	return	0;
}
