#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_BOXES	6

#define	TOWER_1			1
#define	TOWER_2			2

bool	is_higher(const int& a,const int& b)
{
	return	a>b;
}

int		main(void)
{
	int		box[NUM_OF_BOXES+1],h1,h2,t[NUM_OF_BOXES+1];
	bool	found;
	
	for(int i=1;i<=NUM_OF_BOXES;i++)
	{
		cin>>box[i];
		t[i] = TOWER_2;
	}
	cin>>h1>>h2;
	
	sort(&box[1],&box[NUM_OF_BOXES+1],is_higher);
	found = false;
	
	for(int i=1;i<=NUM_OF_BOXES-2&&found!=true;i++)
	{
		for(int j=i+1;j<=NUM_OF_BOXES-1&&found!=true;j++)
		{
			for(int k=j+1;k<=NUM_OF_BOXES&&found!=true;k++)
			{
				if( box[i]+box[j]+box[k] == h1 )
				{
					t[i] = t[j] = t[k] = TOWER_1;
					found = true;
				}
			}
		}
	}
	
	for(int i=1;i<=NUM_OF_BOXES;i++)
	{
		if( t[i] == TOWER_1 )
		{
			cout<<box[i]<<' ';
		}
	}
	
	for(int i=1;i<=NUM_OF_BOXES;i++)
	{
		if( t[i] == TOWER_2 )
		{
			cout<<box[i]<<' ';
		}
	}
	
	cout<<'\n';
	
	return	0;
}
