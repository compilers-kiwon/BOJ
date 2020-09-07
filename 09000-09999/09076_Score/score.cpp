#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_UMPIRES	5

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	score[NUM_OF_UMPIRES+1];
		
		for(int i=1;i<=NUM_OF_UMPIRES;i++)
		{
			cin>>score[i];
		}
		
		sort(&score[1],&score[NUM_OF_UMPIRES+1]);
		
		if( score[NUM_OF_UMPIRES-1]-score[2] >=4 )
		{
			cout<<"KIN\n";
		}
		else
		{
			int	sum,i;
			
			for(i=2,sum=0;i<=NUM_OF_UMPIRES-1;i++)
			{
				sum += score[i];
			}
			cout<<sum<<endl;
		}
		T--;
	}
	return	0;
}
