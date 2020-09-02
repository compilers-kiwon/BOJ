#include	<iostream>
#include	<cmath>

using namespace	std;

void	cantor(string& str,int from,int len)
{
	if( len == 1 )
	{
		return;
	}
	
	int	sub_len;
	
	sub_len = len/3;
	
	for(int i=from+sub_len;i<from+sub_len+sub_len;i++)
	{
		str[i] = ' ';
	}
	
	cantor(str,from,sub_len);
	cantor(str,from+sub_len+sub_len,sub_len);
}

int		main(void)
{
	int	N;
	
	while( scanf("%d",&N) == 1 )
	{
		string	str(pow(3,N),'-');
		
		cantor(str,0,str.length());
		cout<<str<<'\n';
	}
	
	return	0;
}
