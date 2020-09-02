#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	n;
	
	cin>>n;getchar();
	
	for(int i=1;i<=n;i++)
	{
		string	name;
		int		good,bad;
		
		getline(cin,name);
		good = bad = 0;
		
		for(int j=0;j<name.length();j++)
		{
			if( name[j] == 'g' || name[j] == 'G' )
			{
				good++;
			}
			else if( name[j] == 'b' || name[j] == 'B' )
			{
				bad++;
			}
		}
		
		if( good > bad )
		{
			cout<<name<<" is GOOD\n";
		}
		else if( good < bad )
		{
			cout<<name<<" is A BADDY\n";
		}
		else
		{
			cout<<name<<" is NEUTRAL\n";
		}
	}
	
	return	0;
}
