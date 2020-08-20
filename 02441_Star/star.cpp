#include	<iostream>
#include	<string>

using namespace	std;

string	spaces[11] = {
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
	"          ",
};

string    stars[11] = 
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

int	main(void)
{
	int	N,num_of_stars;
	
	cin>>N;
	
	for(num_of_stars=N;num_of_stars>=1;num_of_stars--)
	{
		int	len_of_spaces,i,a,b;
		
		len_of_spaces = N-num_of_stars;
		
		a = len_of_spaces/10;
		b = len_of_spaces%10;
		
		for(i=1;i<=a;i++)
		{
			cout<<spaces[10];
		}
		cout<<spaces[b];
		
		a = num_of_stars/10;
		b = num_of_stars%10; 
		
		for(i=1;i<=a;i++)
		{
			cout<<stars[10];
		}
		cout<<stars[b]<<endl;
	}
	
	return	0;
}
