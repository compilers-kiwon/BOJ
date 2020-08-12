#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

int	main(void)
{
	int			N;
	vector<int>	numbers;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	n,middle;
		
		scanf("%d",&n);
		
		vector<int>::iterator	it;
		
		it = upper_bound(numbers.begin(),numbers.end(),n);
		numbers.insert(it,n);
		
		if( i%2 == 0 )
		{
			middle = i/2-1;
		}
		else
		{
			middle = i/2;
		}
		
		printf("%d\n",numbers[middle]);
	}
	
	return	0;
}
