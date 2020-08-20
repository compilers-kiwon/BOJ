#include	<iostream>

using namespace	std;

int	get_score(int a,int b,int c)
{
	int	result;
	
	if( a==b && b==c )
	{
		result = 10000+a*1000;
	}
	else if( a==b || b==c || a==c )
	{
		int	same;
		
		if( a==b )
		{
			same = a;
		}
		else
		{
			same = c;
		}
		
		result = 1000+same*100;
	}
	else
	{
		result = max(a,max(b,c))*100;
	}
	
	return	result;
}

int	main(void)
{
	int	N,reward,i;
	
	cin>>N;
	
	for(i=1,reward=0;i<=N;i++)
	{
		int	a,b,c;
		
		cin>>a>>b>>c;
		reward = max(reward,get_score(a,b,c));
	}
	cout<<reward<<endl;
	
	return	0;
}
