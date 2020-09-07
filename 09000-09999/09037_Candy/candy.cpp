#include	<iostream>
#include	<vector>

using namespace	std;

bool	have_same_candy(vector<int>& candy,int size)
{
	bool	result;
	int		i;
	
	for(i=0,result=true;i<size-1;i++)
	{
		if( candy[i] != candy[i+1] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		count(vector<int>& candy,int size)
{
	int	cnt;
	
	for(cnt=0;have_same_candy(candy,size)==false;cnt++)
	{
		vector<int>	tmp(size);
		
		for(int i=0;i<size;i++)
		{
			tmp[(i+1)%size] = candy[i]/2;
		}
		
		for(int i=0;i<size;i++)
		{
			candy[i] = candy[i]/2+tmp[i];
			
			if( candy[i]%2 == 1 )
			{
				candy[i]++;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N;
		
		cin>>N;
		
		vector<int>	candy(N);
		
		for(int i=0;i<N;i++)
		{
			cin>>candy[i];
			
			if( candy[i]%2 == 1 )
			{
				candy[i]++;
			}
		}
		
		cout<<count(candy,N)<<'\n';
		
		T--;
	}
	
	return	0;
}
