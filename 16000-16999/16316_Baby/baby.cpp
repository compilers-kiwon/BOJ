#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

int	str2int(string& str)
{
	int	ret,i;
	
	for(i=ret=0;i<str.length();i++)
	{
		ret = ret*10+char2int(str[i]);
	}
	
	return	ret;
}

int	main(void)
{
	int		n;
	bool	flag;
	
	cin>>n;
	flag = true;
	
	for(int i=1;i<=n;i++)
	{
		string	a;
		
		cin>>a;
		
		if( a!="mumble" && str2int(a)!=i )
		{
			flag = false;
			break;
		}
	}
	
	if( flag == true )
	{
		cout<<"makes sense\n";
	}
	else
	{
		cout<<"something is fishy\n";
	}
	
	return	0;
}
