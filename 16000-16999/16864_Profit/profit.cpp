#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

int	str2int(string& str)
{
	int	result,i;
	
	for(i=result=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c != '.' )
		{
			result = result*10+char2int(str[i]);
		}
	}
	
	return	result;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	pt_str,p1_str,p2_str;
	int		pt,p1,p2,cnt;
	
	cin>>pt_str>>p1_str>>p2_str;
	
	pt = str2int(pt_str);
	p1 = str2int(p1_str);
	p2 = str2int(p2_str);
	
	cnt = 0;
	
	for(int i=0;i*p1<=pt;i++)
	{
		int	estimated_profit_of_pizza = pt-i*p1;
		
		if( estimated_profit_of_pizza%p2 == 0 )
		{
			cout<<i<<' '<<estimated_profit_of_pizza/p2<<'\n';
			cnt++;
		}
	}
	
	if( cnt == 0 )
	{
		cout<<"none\n";
	}
	
	return	0;
}
