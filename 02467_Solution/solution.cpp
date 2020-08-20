#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_SOLUTIONS	(100000+1)

int	solution[MAX_NUM_OF_SOLUTIONS];


int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&solution[i]);
	}
	
	sort(&solution[1],&solution[N+1]);
	
	int	left,right,s1,s2,s;
	
	left = 1;
	right = N;
	s = 0x7FFFFFFF;
	
	while( left != right )
	{
		if( abs(solution[left]+solution[right]) < s )
		{
			s1 = solution[left];
			s2 = solution[right];
			s = abs(solution[left]+solution[right]);
		}
		
		if( abs(solution[left]) > abs(solution[right]) )
		{
			++left;
		}
		else
		{
			--right;
		}
	}
	
	printf("%d %d\n",s1,s2);
	
	return	0;
}
