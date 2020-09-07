#include	<iostream>
#include	<string>

using namespace	std;

char	table[4][4] = {{'A','C','A','G'},{'C','G','T','A'},{'A','T','C','G'},{'G','A','G','T'}};

#define	GET_INDEX(c)	(((c)=='A')?0:((c)=='G')?1:((c)=='C')?2:3)

int		main(void)
{
	int		N;
	string	DNA;
	
	cin>>N>>DNA;
	
	for(int i=N-1;i>0;i--)
	{
		char	col,row;
		
		col = DNA[i];
		row = DNA[i-1];
				
		DNA[i-1] = table[GET_INDEX(row)][GET_INDEX(col)];
	}
	cout<<DNA[0]<<endl;
	
	return	0;
}
