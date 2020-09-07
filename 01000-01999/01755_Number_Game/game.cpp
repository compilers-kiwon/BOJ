#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	map<string,int>	numbers;
	map<int,string>	word_table;
	int				M,N;
	
	cin>>M>>N;
	
	word_table[0] = "zero";
	word_table[1] = "one";
	word_table[2] = "two";
	word_table[3] = "three";
	word_table[4] = "four";
	word_table[5] = "five";
	word_table[6] = "six";
	word_table[7] = "seven";
	word_table[8] = "eight";
	word_table[9] = "nine";
	
	for(int i=M;i<=N;i++)
	{
		if( i >= 10 )
		{
			string	str;
			int		n1,n2;
			
			n1 = i/10;
			n2 = i%10;
			
			str = word_table[n1]+" "+word_table[n2];
			numbers[str] = i;	
		}
		else
		{
			string& str = word_table[i];
			numbers[str] = i;	
		}	
	}
	
	map<string,int>::iterator	it;
	int							cnt;
	
	for(it=numbers.begin(),cnt=0;it!=numbers.end();it++)
	{
		cout<<it->second<<' ';
		cnt++;
		
		if( cnt == 10 )
		{
			cnt = 0;
			cout<<'\n';
		}
	}
	
	return	0;
}
