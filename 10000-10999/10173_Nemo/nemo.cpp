#include	<iostream>
#include	<string>

using namespace	std;

#define	compare(c,t,T)	((c)==(t) || (c)==(T))

int	main(void)
{
	while(1)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "EOI" )
		{
			break;
		}
		
		bool	found;
		int		i;
		
		for(i=0,found=false;i<str.length()-4 && found != true;i++)
		{
			if( compare(str[i],'n','N') && compare(str[i+1],'e','E') && compare(str[i+2],'m','M') && compare(str[i+3],'o','O') )
			{
				found = true;
			}
		}
		
		if( found == true )
		{
			cout<<"Found\n";
		}
		else
		{
			cout<<"Missing\n";
		}
	}
	return	0;
}
