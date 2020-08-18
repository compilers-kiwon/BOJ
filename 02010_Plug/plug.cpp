#include	<cstdio>

using namespace	std;

int	main(void)
{
	int	N,i;
	int	num_of_computers;
	int	num_of_plugs;
	
	scanf("%d",&N);
	
	for(num_of_computers=0,i=1;i<=N-1;i++)
	{	
		scanf("%d",&num_of_plugs);
		num_of_computers += num_of_plugs-1;
	}
	
	scanf("%d",&num_of_plugs);
	num_of_computers += num_of_plugs;
	
	printf("%d\n",num_of_computers);
	
	return	0;
}
