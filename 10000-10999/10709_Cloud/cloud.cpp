#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	CLOUD	'c'
#define	EMPTY	'.'

int	main(void)
{
	int	H,W;
	
	cin>>H>>W;
	
	for(int i=1;i<=H;i++)
	{
		string	sky;
		
		cin>>sky;
		
		for(int j=0,prev=-1;j<sky.length();j++)
		{
			if( sky[j] == CLOUD )
			{
				cout<<"0 ";
				prev = 0;
			}
			else
			{
				if( prev == -1 )
				{
					cout<<"-1 ";
				}
				else
				{
					cout<<++prev<<' ';
				}
			}
		}
		cout<<endl;
	}
	return	0;
}
