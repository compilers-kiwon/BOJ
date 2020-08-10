#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<string,char>	Bin_to_Oct;
string				binary,oct;

void	init_Bin_to_Oct(void)
{
	Bin_to_Oct["000"] = '0';
	Bin_to_Oct["001"] = '1';
	Bin_to_Oct["010"] = '2';
	Bin_to_Oct["011"] = '3';
	Bin_to_Oct["100"] = '4';
	Bin_to_Oct["101"] = '5';
	Bin_to_Oct["110"] = '6';
	Bin_to_Oct["111"] = '7';
}

int		main(void)
{
	init_Bin_to_Oct();
	
	cin>>binary;
	
	if( binary.length()%3 == 1 )
	{
		binary.insert(0,"00");
	}
	else if( binary.length()%3 == 2)
	{
		binary.insert(0,"0");
	}
	
	for(int i=0;i<binary.length();i+=3)
	{
		string	sub;
		
		sub = binary.substr(i,3);
		cout<<Bin_to_Oct[sub];
	}
	cout<<endl;
	
	return	0;
}
