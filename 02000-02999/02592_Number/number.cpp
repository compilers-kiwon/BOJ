#include	<iostream>
#include	<map>

using namespace	std;

#define	NUM_OF_NUMS	10

map<int,int>	freq;

int	main(void)
{
	int	sum,avg,i;
	
	for(i=1,sum=0;i<=NUM_OF_NUMS;i++)
	{
		int	n;
		
		cin>>n;
		sum += n;
		++freq[n];
	}
	avg = sum/NUM_OF_NUMS;
	
	int	max_freq,max_freq_num;
	
	map<int,int>::iterator	fi;
	
	for(fi=freq.begin(),max_freq=0;fi!=freq.end();fi++)
	{
		if( fi->second > max_freq )
		{
			max_freq = fi->second;
			max_freq_num = fi->first;
		}
	}
	cout<<avg<<endl<<max_freq_num<<endl;
	
	return	0;
}
