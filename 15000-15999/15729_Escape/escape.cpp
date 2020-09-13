#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000000+1+2)

#define	OFF			0
#define	ON			1
#define	MAX_STATE	2
#define	CHANGE(s)	(((s)+1)%MAX_STATE)

int	state[MAX_SIZE];

int	main(void)
{
	int	N,cnt;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>state[i];
	}
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( state[i] == ON )
		{
			cnt++;
			state[i+1] = CHANGE(state[i+1]);
			state[i+2] = CHANGE(state[i+2]);
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
