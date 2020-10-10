#include	<iostream>
#include	<string>

using namespace	std;

#define	BOY		'B'
#define	GIRL	'G'

#define	INCH_PER_FEET		12
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		get_height(string& str)
{
	int	feet,inch;
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( !IN_RANGE('0',c,'9') )
		{
			c = ' ';
		}
	}
	
	sscanf(str.c_str(),"%d %d",&feet,&inch);
	
	return	feet*INCH_PER_FEET+inch;
}

void	print(int inch)
{
	cout<<inch/INCH_PER_FEET<<'\''<<inch%INCH_PER_FEET<<'\"';
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		char	s;
		string	h1,h2;
		int		m,d,a,lower,upper;
		
		cin>>s>>h1>>h2;
		
		m = get_height(h1);
		d = get_height(h2);
		a = (m+d+(s==BOY?5:-5));
		
		lower = ((a%2)?a+1:a)/2-4;
		upper = a/2+4;
		
		cout<<"Case #"<<t<<": ";
		print(lower);
		cout<<" to ";
		print(upper);
		cout<<'\n';
	}
	
	return	0;
}
