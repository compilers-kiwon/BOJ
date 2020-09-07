#include	<iostream>
//#include	<fstream>
#include	<vector>
#include	<algorithm>

using namespace std;

typedef	unsigned int	uint32;

vector<uint32>	cows;
uint32			N;

int	main(void)
{
	uint32		i,j,k,cnt;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		uint32	pos;
		
		cin>>pos;
		cows.push_back(pos);
	}
	
	sort(cows.begin(),cows.end());
	cnt = 0;
	
	for(i=0;i<N-2;i++)
	{
		for(j=i+1;j<N-1;j++)
		{
			uint32	distance_1;
			
			distance_1 = cows[j]-cows[i];
			
			for(k=j+1;k<N;k++)
			{
				uint32	distance_2;
				
				distance_2 = cows[k]-cows[j];
				
				if( distance_1<=distance_2 && distance_2<=2*distance_1 )
				{
					cnt++;
				}
			}
		}
	}
	
	cout<<cnt<<endl;
		
	return	0;
}
