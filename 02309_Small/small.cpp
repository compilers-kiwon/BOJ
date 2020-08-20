#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace std;

#define	NUM_OF_SMALLS	9

vector<int>	small(NUM_OF_SMALLS+1),answer;

bool	find_smalls(int num_of_smalls,int sum,int index)
{
	if( num_of_smalls == 7 )
	{
		if( sum == 100 )
		{
			return	true;
		}
		return	false;
	}
	
	for(int i=index;i<=num_of_smalls+3;i++)
	{
		answer.push_back(small[i]);
		
		if( find_smalls(num_of_smalls+1,sum+small[i],i+1) == true )
		{
			return	true;
		}
		
		answer.pop_back();
	}
	return	false;
}

int		main(void)
{
	int	i;
	
	small[0] = 0;
	
	for(i=1;i<=NUM_OF_SMALLS;i++)
	{
		int	h;
		
		cin>>small[i];
	}
	
	sort(small.begin(),small.end());
	
	for(i=1;i<=NUM_OF_SMALLS-6;i++)
	{
		answer.push_back(small[i]);
		
		if( find_smalls(1,small[i],i+1) == true )
		{
			break;
		}
		
		answer.pop_back();
	}
	
	for(i=0;i<7;i++)
	{
		cout<<answer[i]<<endl;
	}
	
	return	0;
}
