#include	<iostream>
#include	<vector>

using namespace	std;

vector<int>	fibo;

int	main(void)
{
	fibo.push_back(0);	// f0
	fibo.push_back(1);	// f1
	
	for(int i=2;;i++)
	{
		int	f;
		
		f = fibo[i-1]+fibo[i-2];
		
		if( f > 1000000000 )
		{
			break;
		}
		fibo.push_back(f);
	}
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		vector<int>	fibo_comb;
		int	lo,hi,mid,n;
		
		cin>>n;
		
		while(n>0)
		{
			lo = 0;
			hi = fibo.size();
			
			while(lo+1<hi)
			{
				mid = (lo+hi)/2;
				
				if( fibo[mid] < n )
				{
					lo = mid;
				}
				else if( fibo[mid] > n )
				{
					hi = mid;
				}
				else
				{
					lo = mid;
					break;
				}
			}
			
			fibo_comb.push_back(lo);
			n -= fibo[lo];
		}
		
		for(int i=fibo_comb.size()-1;i>=0;i--)
		{
			cout<<fibo[fibo_comb[i]]<<' ';
		}
		cout<<endl;
		
		T--;
	}
	return	0;
}
