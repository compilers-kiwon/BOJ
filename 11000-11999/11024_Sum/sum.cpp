#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T,sum;
	
	cin>>T;
	
	while(T>0)
	{
		char	c;
		
		for(sum=0,c='\0';c!='\n';c=getchar())
		{
			int	n;
			
			cin>>n;
			sum += n;
		}
		cout<<sum<<endl;
		
		T--;
	}
	return	0;
}
