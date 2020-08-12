#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace std;

#define	MAX_NUM	(100000+1)

int			table[MAX_NUM];
vector<int>	pow_num;

int	get_num_of_poly(int n)
{
	int	min_len,i,to;
	
	to = pow_num.size()-1;
	
	for(min_len=0x7FFFFFFF,i=0;i<=to;i++)
	{
		min_len = min(min_len,1+table[n-pow_num[i]]);
	}
	return	min_len;
}

int	main(void)
{
	int	N;
	
	cin>>N;
	
	table[1] = 1;
	pow_num.push_back(1);
	
	for(int i=2;i<=N;i++)
	{
		int	s;
		
		s = sqrt(i);
		
		if( s*s == i )
		{
			table[i] = 1;
			pow_num.push_back(i);
		}
		else
		{
			table[i] = get_num_of_poly(i);
		}
	}
	cout<<table[N]<<endl;
	
	return	0;
}
