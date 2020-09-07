#include	<iostream>
#include	<fstream>

using namespace std;

#define	MAX_NUM_OF_TOWERS	(500000+1)

typedef	unsigned int	uint32;

typedef	pair<uint32,uint32>	Tower;	// first:index, second:height

uint32	N;
Tower	stack[MAX_NUM_OF_TOWERS];
uint32	receiver[MAX_NUM_OF_TOWERS];

int	main(void)
{
	cin>>N;
	
	uint32	i,top;
	
	top=0;
	stack[top].first = stack[top].second = 0;
	
	for(i=1;i<=N;i++)
	{
		Tower	t;
		
		cin>>t.second;t.first=i;
		
		while( top != 0 )
		{
			if( stack[top].second >= t.second )
			{
				break;
			}
			--top;
		}
		
		receiver[i] = stack[top].first;
		stack[++top] = t;
	}
	
	for(i=1;i<=N;i++)
	{
		cout<<receiver[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
