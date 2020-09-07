#include	<iostream>
#include	<vector>

using namespace std;

vector<int>	numbers,sum;

int	main(void)
{
	int	n,i,max_sum;
	
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		int	num;
		
		cin>>num;
		numbers.push_back(num);
	}
	
	sum.push_back(numbers[0]);
	
	for(i=1;i<n;i++)
	{
		if( sum[i-1]+numbers[i] > numbers[i] )
		{
			sum.push_back(sum[i-1]+numbers[i]);
		}
		else
		{
			sum.push_back(numbers[i]);
		}
	}
	
	for(i=1,max_sum=sum[0];i<n;i++)
	{
		if( sum[i] > max_sum )
		{
			max_sum = sum[i];
		}
	}
	
	cout<<max_sum<<endl;
	
	return	0;
}
