#include	<iostream>
#include	<map>

using namespace	std;

map<int,char>	table;

void	init_table(void)
{
	int		i;
	char	c;
	
	for(i=0,c='0';i<=9;i++,c++)
	{
		table[i] = c;
	}
	
	for(i=10,c='A';i<=35;i++,c++)
	{
		table[i] = c;
	}
}

void	change(string& ret,int N,int B)
{
	while( N != 0 )
	{
		ret.insert(ret.begin(),table[N%B]);
		N /= B;
	}
}

int		main(void)
{
	int		N,B;
	string	answer;
	
	init_table();
	
	cin>>N>>B;
	change(answer,N,B);
	cout<<answer<<endl;
	
	return	0;
}
