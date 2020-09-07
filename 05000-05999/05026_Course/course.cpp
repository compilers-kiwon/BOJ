#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

int	get_num(string& exp,int& index)
{
	int	value;
	
	for(value=0;index<exp.length();++index)
	{
		if( exp[index] < '0' || exp[index] > '9' )
		{
			break;
		}
		
		value = value*10+char2int(exp[index]);
	}
	
	return	value;
}

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	exp;
		int		a,b,index;
		
		cin>>exp;
		
		if( exp[0] == 'P' )
		{
			cout<<"skipped\n";
			continue;
		}
		
		index = 0;
		
		a = get_num(exp,index);
		index++;
		b = get_num(exp,index);
		
		cout<<a+b<<endl;
	}
	
	return	0;
}
