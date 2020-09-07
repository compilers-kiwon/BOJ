#include	<iostream>
#include	<string>

using namespace	std;

string	star[11] =
{
	"",
	"*",
	"**",
	"***",
	"****",
	"*****",
	"******",
	"*******",
	"********",
	"*********",
	"**********"
};

string	space[11] =
{
	"",
	" ",
	"  ",
	"   ",
	"    ",
	"     ",
	"      ",
	"       ",
	"        ",
	"         ",
	"          "
};

void	print_space(int n)
{
	int	ten,one,i;
	
	ten = n/10;
	one = n%10;
	
	for(i=1;i<=ten;i++)
	{
		cout<<space[10];
	}
	cout<<space[one];
}

void	print_star(int n)
{
	int	ten,one,i;
	
	ten = n/10;
	one = n%10;
	
	for(i=1;i<=ten;i++)
	{
		cout<<star[10];
	}
	cout<<star[one];
}

int		main(void)
{
	int	n,i,j;
	
	cin>>n;
	
	for(i=1,j=n-1;i<=n;i++,j--)
	{
		print_space(j);
		print_star(2*i-1);
		cout<<endl;
	}
	
	return	0;
}
