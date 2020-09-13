#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM	9000000
	
bool		prime_table[MAX_NUM+1];
vector<int>	prime_numbers;
	
void	build_table(void)
{
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( prime_table[i] == false )
		{
			prime_numbers.push_back(i);
			
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				prime_table[j] = true;
			}
		}
	}
}

int		main(void)
{
	build_table();
	
	sort(prime_numbers.begin(),prime_numbers.end());
	
	int	K;
	
	cout<<prime_numbers.size()<<endl;
	cin>>K;
	cout<<prime_numbers[K-1]<<endl;
	
	return	0;
}
