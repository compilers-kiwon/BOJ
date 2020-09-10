#include	<iostream>
#include	<string>

using namespace	std;

bool	compare_table(int* t1,int* t2)
{
	bool	result;
	char	c;
	
	for(c='a',result=true;c<='z'&&result!=false;c++)
	{
		if( t1[(int)c] != t2[(int)c] )
		{
			result = false;
		}
	}
	
	return	result;
}

void	build_table(string& str,int* table)
{
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		table[(int)c]++;
	}
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	str1,str2;
		int		table1[0x100],table2[0x100];
		
		cin>>str1>>str2;
		
		for(char c='a';c<='z';c++)
		{
			table1[(int)c] = table2[(int)c] = 0;
		}
		
		build_table(str1,table1);
		build_table(str2,table2);
		
		if( compare_table(table1,table2) == true )
		{
			puts("Possible");
		}
		else
		{
			puts("Impossible");
		}
	}
	
	return	0;
}
