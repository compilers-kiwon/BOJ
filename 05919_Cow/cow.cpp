#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int			N,sum,avg;
	vector<int>	num_of_hay_bales;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	sum = 0;
	
	for(int i=0;i<N;i++)
	{
		int	h;
		
		cin>>h;
		num_of_hay_bales.push_back(h);
		sum += h;
	}
	
	avg = sum/N;
	sum = 0;
	
	for(int i=0;i<N;i++)
	{
		if( num_of_hay_bales[i] < avg )
		{
			sum += avg-num_of_hay_bales[i];
		}
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
