#include	<iostream>

using namespace	std;

#define	MAX_SIZE			6
#define	get_next(n,offset)	(((n)+(offset))%MAX_SIZE)

int	main(void)
{
	int	K,line[MAX_SIZE];
	
	cin>>K;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		int	n;
		
		cin>>n>>line[i];
	}
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		int	tmp[MAX_SIZE];
		
		for(int j=0;j<MAX_SIZE;j++)
		{
			tmp[j] = line[get_next(i,j)];
		}
		
		if( (tmp[0]==tmp[2]+tmp[4]) && (tmp[1]==tmp[3]+tmp[5]) )
		{
			cout<<((tmp[0]*tmp[1])-(tmp[3]*tmp[4]))*K<<'\n';
			break;
		}
	}
	
	return	0;
}
