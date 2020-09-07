#include	<iostream>

using namespace std;

void	print_line(int len_of_space,int len_of_star)
{
	for(int i=1;i<=len_of_space;i++)
	{
		cout<<' ';
	}
	
	for(int i=1;i<=len_of_star;i++)
	{
		cout<<'*';
	}
	cout<<endl;
}

int		main(void)
{	
	int	N;
	
	cin>>N;
	
	for(int i=N;i>=1;i--)
	{
		print_line(N-i,2*i-1);
	}
	
	return	0;
}
