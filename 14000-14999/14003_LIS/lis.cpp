#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MIN	-2000000000

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int	N,A;
		
	cin>>N;
	
	vector<int>	number,lis_number,lis_index,prev_index(N,-1);
	
	for(int i=0;i<N;i++)
	{
		vector<int>::iterator	it;
		
		cin>>A;
		
		number.push_back(A);
		it = lower_bound(lis_number.begin(),lis_number.end(),A);
		
		if( it == lis_number.end() )
		{
			if( lis_number.size() == 0)
			{
				prev_index[i] = -1;
			}
			else
			{
				prev_index[i] = lis_index.back();
			}
			
			lis_number.push_back(A);
			lis_index.push_back(i);
		}
		else
		{
			if( it == lis_number.begin() )
			{
				prev_index[i] = -1;
			}
			else
			{
				prev_index[i] = lis_index[(it-1)-lis_number.begin()];
			}
			
			*it = A;
			lis_index[it-lis_number.begin()] = i;
		}
	}
	
	vector<int>	out;
	
	cout<<lis_number.size()<<'\n';
	
	for(int i=lis_index.back();i!=-1;i=prev_index[i])
	{
		out.push_back(number[i]);
	}
	
	for(int i=out.size()-1;i>=0;i--)
	{
		cout<<out[i]<<' ';
	}
	
	return	0;
}
