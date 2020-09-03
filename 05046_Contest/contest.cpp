#include	<iostream>

using namespace	std;

int	main(void)
{
	bool	result;
	int		N,B,H,W,answer;
	
	cin>>N>>B>>H>>W;
	result = false;
	answer = 0x7FFFFFFF;
	
	for(int i=1;i<=H&&result==false;i++)
	{
		int	c;
		
		cin>>c;
		
		for(int j=1;j<=W&&result==false;j++)
		{
			int	n,t;
			
			cin>>n;
			t = c*N;
			
			if( n >= N && t <= B && t < answer )
			{
				answer = t;
			}
		}
	}
	
	if( answer != 0x7FFFFFFF )
	{
		cout<<answer<<endl;
	}
	else
	{
		cout<<"stay home\n";
	}
	
	return	0;
}
