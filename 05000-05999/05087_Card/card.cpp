#include	<iostream>
#include	<vector>

using namespace	std;

#define	is_even(n)	((n)%2==0)
#define	char2int(c)	((int)((c)-'0'))

int	main(void)
{
	for(;;)
	{
		string		str;
		vector<int>	num;
		int			n,Cheryl_score,Tania_score;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		n = Cheryl_score = Tania_score = 0;
				
		for(int i=0;i<str.length();i++)
		{
			if( str[i] == '*' )
			{
				break;
			}
			
			if( str[i] == 'A' )
			{
				n = 1;
				continue;
			}
			
			if( str[i] == ' ' )
			{
				num.push_back(n);
				n = 0;
				
				continue;
			}
			
			n = n*10+char2int(str[i]);
		}
		
		for(int i=0;i<num.size();i++)
		{
			if( is_even(num[i]) == true )
			{
				Tania_score++;
			}
			else
			{
				Cheryl_score++;
			}
		}
		
		if( Tania_score > Cheryl_score )
		{
			cout<<"Tania\n";
		}
		else if( Tania_score < Cheryl_score )
		{
			cout<<"Cheryl\n";
		}
		else
		{
			cout<<"Draw\n";
		}
	}
	
	return	0;
}
