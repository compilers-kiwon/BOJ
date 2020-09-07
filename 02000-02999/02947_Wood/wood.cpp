#include	<iostream>

using namespace	std;

#define	NUM_OF_WOODS	5

bool	is_sorted(int* w)
{
	bool	result;
	int		i;
	
	for(result=true,i=2;i<=NUM_OF_WOODS;i++)
	{
		if( w[i-1] > w[i] )
		{
			result = false;
			break;
		}
	}
	return	result;
}

bool	is_swapped(int& w1,int& w2)
{
	if( w1 > w2 )
	{
		swap(w1,w2);
		return	true;
	}
	return	false;
}

void	print(int* w)
{
	for(int i=1;i<=NUM_OF_WOODS;i++)
	{
		cout<<w[i]<<' ';
	}
	cout<<endl;
}

int		main(void)
{
	int	wood[NUM_OF_WOODS+1];
	
	for(int i=1;i<=NUM_OF_WOODS;i++)
	{
		cin>>wood[i];
	}
	
	while( is_sorted(wood) != true )
	{
		for(int i=1;i<=NUM_OF_WOODS-1;i++)
		{
			if( is_swapped(wood[i],wood[i+1]) == true )
			{
				print(wood);
			}
		}
	}
	
	return	0;
}
