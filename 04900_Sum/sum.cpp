#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	MAX_SIZE	10

const string int2str[MAX_SIZE] = {"063","010","093","079","106","103","119","011","127","107"};

map<string,int>	str2int;

void	parse(string& exp,string& op1,string& op2)
{
	int	i;
	
	for(i=0;exp[i]!='+';i++)
	{
		op1.push_back(exp[i]);
	}
	
	for(++i;exp[i]!='=';i++)
	{
		op2.push_back(exp[i]);
	}
}

int		get_value(string& str)
{
	int	result,i;
	
	for(i=result=0;i<str.length();i+=3)
	{
		string	tmp;
		
		tmp.push_back(str[i]);
		tmp.push_back(str[i+1]);
		tmp.push_back(str[i+2]);
		
		result = result*10+str2int[tmp];
	}
	
	return	result;
}

void	convert(int n,string& str)
{
	for(;n>0;n/=10)
	{
		str.insert(0,int2str[n%10]);
	}
}

int		main(void)
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		str2int[int2str[i]] = i;
	}
	
	cin.sync_with_stdio(false);
	
	while(1)
	{
		string	exp,op1,op2,result;
		int		op1_value,op2_value,sum;
		
		cin>>exp;
		
		if( exp == "BYE" )
		{
			break;
		}
		
		parse(exp,op1,op2);
		
		op1_value = get_value(op1);
		op2_value = get_value(op2);
		
		convert(op1_value+op2_value,result);
		
		cout<<exp<<result<<'\n';
	}
	
	return	0;
}
