#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_NUMS	(100000+1)
#define	MAX_NUM			(2000+1)

vector<bool>	input_table(MAX_NUM,false);
vector<int>		number;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		
		if( input_table[n+1000] == false )
		{
			input_table[n+1000] = true;
			number.push_back(n);
		}
	}
	
	sort(number.begin(),number.end());
	
	for(int i=0;i<number.size();i++)
	{
		cout<<number[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
