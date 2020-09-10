#include <iostream>

using namespace std;

int get_sum_of_digit(int n)
{
	int sum_of_digit;
	
	for(sum_of_digit=0;n>0;n/=10)
	{
		sum_of_digit += n%10;
	}
	
	return sum_of_digit;
}

int main(void)
{
	int L,D,X,N,M;
	
	cin>>L>>D>>X;
	N = 0x100000;
	M = 0;
	
	for(int i=L;i<=D;i++)
	{
		int sum;
		
		sum = get_sum_of_digit(i);
		
		if( sum == X )
		{
			N = min(N,i);
			M = max(M,i);
		}
	}
	
	cout<<N<<'\n'<<M<<'\n';
	
	return 0;
}
