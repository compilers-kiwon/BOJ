#include	<iostream>
#include	<string>

using namespace	std;

#define	A		0
#define	B		1
#define	A_AND_B	2
#define	A_OR_B	3
#define	A_XOR_B	4
#define	NOT_A	5
#define	NOT_B	6
#define	MAX_BIN	7

int	main(void)
{
	string	bin[MAX_BIN];
	int		i,len;
	
	cin>>bin[A]>>bin[B];
	
	for(i=0,len=bin[A].length();i<len;i++)
	{
		char	a,b;
		
		a = bin[A][i];
		b = bin[B][i];
		
		bin[A_AND_B].push_back((a=='1'&&b=='1')?'1':'0');
		bin[A_OR_B].push_back((a=='0'&&b=='0')?'0':'1');
		bin[A_XOR_B].push_back((a!=b)?'1':'0');
		bin[NOT_A].push_back((a=='1')?'0':'1');
		bin[NOT_B].push_back((b=='1')?'0':'1');
	}
	
	for(int i=A_AND_B;i<=NOT_B;i++)
	{
		cout<<bin[i]<<'\n';
	}
	
	return	0;
}
