#include	<iostream>
#include	<string>

using namespace	std;

#define	CHAR2INT(C)	((int)((C)-'A')+1)

int	main(void)
{
	string	name;
	int		N,sum,i;
	
	cin>>N>>name;
	
	for(sum=i=0;i<N;i++)
	{
		sum += CHAR2INT(name[i]);
	}
	cout<<sum<<endl;
	
	return	0;
}
