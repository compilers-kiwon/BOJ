#include	<iostream>
#include	<string>

using namespace	std;

#define	GET_INDEX(c)	(((c)>='A'&&(c)<='Z')?(int)((c)-'A'):((c)>='a'&&(c)<='z')?(int)((c)-'a'):-1)

int	main(void)
{
	int	N;
	
	cin>>N;
	getchar();
	
	while(N>0)
	{
		string	str;
		int		cnt,i;
		bool	table[26];
		
		getline(cin,str);
		
		for(int i=0;i<26;i++)
		{
			table[i] = false;
		}
		
		for(i=cnt=0;i<str.length();i++)
		{
			int	index;
			
			index = GET_INDEX(str[i]);
			
			if( index >= 0 && table[index] == false )
			{
				++cnt;
				table[index] = true;
			}
		}
		
		if( cnt == 26 )
		{
			cout<<"pangram\n";
		}
		else
		{
			cout<<"missing ";
			
			for(int i=0;i<26;i++)
			{
				if( table[i] == false )
				{
					cout<<(char)(i+(int)'a');
				}
			}
			cout<<endl;
		}
		
		N--;
	}
	
	return	0;
}
