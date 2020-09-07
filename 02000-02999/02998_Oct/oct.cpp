#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<string,char>	bin2oct;

void	add_zero_to_bin(string& bin)
{
	if( (bin.length()+1)%3 == 0 )
	{
		bin.insert(0,"0");
	}
	else if( (bin.length()+2)%3 == 0 )
	{
		bin.insert(0,"00");
	}
	else
	{
		// do nothing
	}
}

void	init_bin2oct(void)
{
	bin2oct["000"] = '0';
	bin2oct["001"] = '1';
	bin2oct["010"] = '2';
	bin2oct["011"] = '3';
	bin2oct["100"] = '4';
	bin2oct["101"] = '5';
	bin2oct["110"] = '6';
	bin2oct["111"] = '7';
}

int		main(void)
{
	string	bin,oct;
	
	init_bin2oct();
	
	cin>>bin;
	add_zero_to_bin(bin);
	
	while( bin.length() > 0 )
	{
		string	sub;
		
		sub = bin.substr(0,3);
		oct.push_back(bin2oct[sub]);
		bin.erase(0,3);
	}
	cout<<oct<<endl;
	
	return	0;
}
