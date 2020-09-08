#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,a,prev,i;
	bool	flag;
	
	cin>>N;
	
	for(prev=0,i=1,flag=true;flag==true&&i<=N;i++)
	{
		cin>>a;
		
		if( a < prev )
		{
			flag = false;
		}
		
		prev = a;
	}
	
	if( flag == true )
	{
		cout<<"yes\n";
	}
	else
	{
		cout<<"no\n";
	}
	
	return	0;
}
