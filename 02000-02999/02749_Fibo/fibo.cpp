#include	<iostream>
#include	<vector>

using namespace	std;

#define	MOD	1000000

vector<int>	fibo;

bool	is_repeated(void)
{
	bool	result = true;
	int		s,e;
	
	for(s=0,e=fibo.size()/2;e<fibo.size();s++,e++)
	{
		if( fibo[s] != fibo[e] )
		{
			result = false;
			break;
		}
	}
	return	result;
}

int		main(void)
{
	fibo.push_back(0);
	fibo.push_back(1);
	
	int i;
	
	for(i=2;;i++)
	{
		if( i%2 == 0 )
		{
			if( is_repeated() == true )
			{
				break;
			}
		}
		fibo.push_back((fibo[i-2]+fibo[i-1])%MOD);
	}
	
	int	period_num = i/2;
	
	unsigned long long	n;
	
	cin>>n;
	cout<<fibo[n%(unsigned long long)period_num]<<endl;
	
	return	0;
}
