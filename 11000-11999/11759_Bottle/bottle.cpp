#include	<iostream>

using namespace	std;

#define	INF	0x10000000

int	main(void)
{
	int	s,v1,v2,num_of_v1,num_of_v2;
	
	cin>>s>>v1>>v2;
	num_of_v1 = num_of_v2 = INF;
	
	for(int i=0;v1*i<=s;i++)
	{
		if( (s-v1*i)%v2 == 0 )
		{
			int j;
			
			j = (s-v1*i)/v2;
			
			if( i+j < num_of_v1+num_of_v2 )
			{
				num_of_v1 = i;
				num_of_v2 = j;
			}
		}
	}
	
	if( num_of_v1==INF && num_of_v2==INF )
	{
		cout<<"Impossible\n";
	}
	else
	{
		cout<<num_of_v1<<' '<<num_of_v2<<'\n';
	}
	
	return	0;
}
