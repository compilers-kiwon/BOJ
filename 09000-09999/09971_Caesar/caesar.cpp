#include	<iostream>
#include	<string>

using namespace	std;

#define	get_index(c)	((int)((c)-'A'))
#define	get_plain(c)	((get_index((c))+21)%26)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))


int	main(void)
{
	string	text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	while(1)
	{
		string	in,out;
		
		getline(cin,in);
		
		if( in == "ENDOFINPUT" )
		{
			break;
		}
		
		getline(cin,in);
		
		for(int i=0;i<in.length();i++)
		{
			char&	c = in[i];
			
			if( IN_RANGE('A',c,'Z') )
			{
				out.push_back(text[get_plain(c)]);
			}
			else
			{
				out.push_back(c);
			}
		}
		cout<<out<<'\n';
		
		getline(cin,in);
	}
	
	return	0;
}
