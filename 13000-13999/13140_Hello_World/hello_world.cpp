#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	MAX_NUM	10

map<char,int>	char2int;
bool			used[MAX_NUM];
int				N,n1,n2;

bool	do_operation(void)
{
	n1 = char2int['h']*10000+char2int['e']*1000+char2int['l']*110+char2int['o'];
	n2 = char2int['w']*10000+char2int['o']*1000+char2int['r']*100+char2int['l']*10+char2int['d'];
	
	return	(n1+n2 == N);
}

bool	map_char2int(string& str,int index)
{
	if( index == str.length() )
	{
		return	do_operation();
	}
	
	int	i;
	
	if( str[index] == 'h' || str[index] == 'w' )
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	
	for(;i<MAX_NUM;i++)
	{
		if( used[i] == false )
		{
			char2int[str[index]] = i;
			
			used[i] = true;
			
			if( map_char2int(str,index+1) == true )
			{
				return	true;
			}
			
			used[i] = false;
		}
	}
	
	return	false;
}

int		main(void)
{
	string	str = "dehlorw";
	
	cin>>N;
	
	if( map_char2int(str,0) == true )
	{
		printf("  %d\n",n1);
		printf("+ %d\n",n2);
		printf("-------\n");
		
		if( N >= 100000 )
		{
			printf(" %d\n",N);
		}
		else
		{
			printf("  %d\n",N);
		}
	}
	else
	{
		puts("No Answer");
	}
	
	return	0;
}
