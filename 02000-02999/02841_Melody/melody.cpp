#include	<iostream>
#include	<vector>

using namespace	std;

#define	NUM_OF_TONE	6

vector<int>	tone[NUM_OF_TONE+1];

int	main(void)
{
	int	N,P,cnt,i;
	
	scanf("%d %d",&N,&P);
		
	for(int i=1;i<=NUM_OF_TONE;i++)
	{
		tone[i].push_back(0);
	}
	
	for(cnt=0,i=1;i<=N;i++)
	{
		int	a,b;
		
		scanf("%d %d",&a,&b);
		
		if( tone[a].back() < b )
		{
			cnt++;
			tone[a].push_back(b);
		}
		else
		{
			while( tone[a].back() > b )
			{
				tone[a].pop_back();
				cnt++;
			}
			
			if( tone[a].back() < b )
			{
				cnt++;
				tone[a].push_back(b);
			}
			
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
