#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	N,K,answer;
	
	cin>>N>>K;
	
	vector<bool>	table(N+1,false);
	
	for(int i=2;i<=N;i++)
	{
		if( table[i] == false )
		{
			table[i] = true;
			--K;
			
			if( K == 0 )
			{
				answer = i;
				break;
			}
			
			for(int j=i+i;j<=N;j=j+i)
			{
				if( table[j] == false )
				{
					table[j] = true;
					--K;
					
					if( K == 0 )
					{
						answer = j;
						break;
					}
				}
			}
			
			if( K == 0 )
			{
				break;
			}
		}
	}
	cout<<answer<<endl;
	
	return	0;
}
