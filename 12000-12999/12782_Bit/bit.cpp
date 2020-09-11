#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	N,M;
		int		num_of_zero_in_N,num_of_zero_in_M,len;
	
		cin>>N>>M;
		num_of_zero_in_N = num_of_zero_in_M = len = 0;
		
		for(int i=0;i<N.length();i++)
		{
			if( N[i] == M[i] )
			{
				continue;
			}
			
			if( N[i] == '0' )
			{
				num_of_zero_in_N++;
			}
			else
			{
				num_of_zero_in_M++;
			}
			len++;
		}
		cout<<abs(num_of_zero_in_N-num_of_zero_in_M)+(len-abs(num_of_zero_in_N-num_of_zero_in_M))/2<<endl;
		
		T--;
	}
	return	0;
}
