#include	<iostream>
#include	<fstream>
#include	<string>
#include	<map>

using namespace std;

map<string,int>	count;

void	count_coin_sequence(string& sequence)
{
	int	i;
	
	for(i=0;i<38;i++)
	{
		string	seq;
		
		seq = sequence.substr(i,3);
		count[seq]++;
	}
}

void	print_count(void)
{
	cout<<count["TTT"]<<" "<<count["TTH"]<<" "<<
		  count["THT"]<<" "<<count["THH"]<<" "<<
		  count["HTT"]<<" "<<count["HTH"]<<" "<<
		  count["HHT"]<<" "<<count["HHH"]<<endl;
}

int		main(void)
{
	ifstream	in;
	int			P;
	
	in.open("data.txt");
	in>>P;
	
	while(P>0)
	{
		string	result;
		
		in>>result;
		count_coin_sequence(result);
		print_count();
		count.clear();
		P--;
	}
	in.close();
	
	return	0;
}
