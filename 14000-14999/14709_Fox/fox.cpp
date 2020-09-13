#include	<iostream>

using namespace	std;

#define	NUM_OF_FINGERS	(5+1)

bool	finger[NUM_OF_FINGERS][NUM_OF_FINGERS];

const bool	fox_sign[NUM_OF_FINGERS][NUM_OF_FINGERS] = 
{
	{false,false,false,false,false,false},
	{false,false,false, true, true,false},
	{false,false,false,false,false,false},
	{false, true,false,false, true,false},
	{false, true,false, true,false,false},
	{false,false,false,false,false,false}
};

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	f1,f2;
		
		cin>>f1>>f2;
		finger[f1][f2] = finger[f2][f1] = true;
	}
	
	bool	fox;
	
	fox = true;
	
	for(int i=1;i<=NUM_OF_FINGERS&&fox==true;i++)
	{
		for(int j=1;j<=NUM_OF_FINGERS&&fox==true;j++)
		{
			if( finger[i][j] != fox_sign[i][j] )
			{
				fox = false;
			}
		}
	}
	
	if( fox == true )
	{
		cout<<"Wa-pa-pa-pa-pa-pa-pow!\n";
	}
	else
	{
		cout<<"Woof-meow-tweet-squeek\n";
	}
	
	return	0;
}
