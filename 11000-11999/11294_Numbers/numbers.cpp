#include	<iostream>
#include	<string>

using namespace	std;

const string	convert_table = "0123456789ABCDEFGHIJ";

void	convert(int n,int base,string& c)
{
	for(;n>0;n/=base)
	{
		c.push_back(convert_table[n%base]);
	}
	
	for(int h=0,t=c.length()-1;h<t;h++,t--)
	{
		swap(c[h],c[t]);
	}
}

int		main(void)
{
	for(;;)
	{
		string	creature;
		
		getline(cin,creature);
		
		if( creature == "#" )
		{
			break;
		}
		
		int		b,n;
		string	converted;
		
		cin>>b>>n;getchar();
		convert(n,b,converted);
		
		cout<<creature<<", "<<n<<", "<<converted<<'\n';
	}
	
	return	0;
}
