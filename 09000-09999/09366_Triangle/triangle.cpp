#include	<iostream>
#include	<algorithm>
#include	<string>

using namespace	std;

#define	LO			0
#define	MID			1
#define	HI			2
#define	NUM_OF_LINE	3

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int		L[NUM_OF_LINE];
		string	answer;
		
		cin>>L[LO]>>L[MID]>>L[HI];
		sort(&L[0],&L[NUM_OF_LINE]);
		
		if( L[LO]+L[MID] <= L[HI] )
		{
			answer = "invalid!\n";
		}
		else
		{
			if( L[LO]==L[MID] && L[MID]==L[HI] )
			{
				answer = "equilateral\n";
			}
			else
			{
				if( L[LO]==L[MID] || L[MID]==L[HI] )
				{
					answer = "isosceles\n";
				}
				else
				{
					answer = "scalene\n";
				}
			}
		}
		
		cout<<"Case #"<<i<<": "<<answer;
	}
	
	return	0;
}
