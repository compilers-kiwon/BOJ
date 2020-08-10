#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_LEN	(1000+1)

vector<int>	numbers;

void	init_numbers(void)
{
	for(int i=1;numbers.size()<MAX_LEN;++i)
	{
		for(int j=1;j<=i;j++)
		{
			numbers.push_back(i);
		}
	}
}

int		main(void)
{
	init_numbers();
	
	int	A,B,sum;
	
	cin>>A>>B;
	--A,--B;
	
	for(sum=0;A<=B;++A)
	{
		sum += numbers[A];
	}
	cout<<sum<<endl;
	
	return	0;
}
