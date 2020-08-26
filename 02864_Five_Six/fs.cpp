#include	<iostream>
#include	<string>

using namespace	std;

void	change_number(string& n,char from,char to)
{
	for(int i=0;i<n.length();i++)
	{
		if( n[i] == from )
		{
			n[i] = to;
		}
	}
}

int		str2int(string& n)
{
	int	value = 0;
	
	for(int i=0;i<n.length();i++)
	{
		value = value*10+(int)(n[i]-'0'); 
	}
	return	value;
}

int	main(void)
{
	string	n1,n2;
	int		min_n1,min_n2,max_n1,max_n2;
	
	cin>>n1>>n2;
	
	change_number(n1,'5','6');
	change_number(n2,'5','6');
	
	max_n1 = str2int(n1);
	max_n2 = str2int(n2);
	
	change_number(n1,'6','5');
	change_number(n2,'6','5');
	
	min_n1 = str2int(n1);
	min_n2 = str2int(n2);
	
	cout<<min_n1+min_n2<<' '<<max_n1+max_n2<<endl;
	
	return	0;
}
