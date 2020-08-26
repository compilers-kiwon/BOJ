#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace std;

vector<int>	numbers;

int	main(void)
{
	int	N,i;
	
	cin>>N;
	
	for(i=0;i<N;i++)
	{
		int	n;
		
		cin>>n;
		numbers.push_back(n);
	}
	
	sort(numbers.begin(),numbers.end());
	
	for(i=0;i<N;i++)
	{
		cout<<numbers[i]<<endl;
	}
		
	return	0;
}
