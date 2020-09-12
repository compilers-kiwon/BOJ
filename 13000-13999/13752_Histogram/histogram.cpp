#include	<iostream>

using namespace	std;

void	print_ten(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"==========";
	}
}

void	print_one(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"=";
	}
}

int		main(void)
{
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	k;
		
		cin>>k;
		
		print_ten(k/10);
		print_one(k%10);
		puts("");
	}
	
	return	0;
}
