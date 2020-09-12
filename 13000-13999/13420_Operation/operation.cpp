#include	<iostream>
#include	<string>

using namespace	std;

typedef	long long int	int64;

int	main(void)
{
	int	T;
	
	cin>>T;getchar();
	
	while(T>0)
	{
		string	expression,answer;
		int64	n1,n2,n3,result;
		char	op1,op2;
		
		getline(cin,expression);
		sscanf(expression.c_str(),"%lld %c %lld %c %lld",&n1,&op1,&n2,&op2,&n3);
		
		switch(op1)
		{
			case	'+':
				result = n1+n2;
				break;
			case	'-':
				result = n1-n2;
				break;
			case	'*':
				result = n1*n2;
				break;
			case	'/':
				result = n1/n2;
				break;
			default:
				// To Do
				break;
		}
		
		if( result == n3 )
		{
			cout<<"correct\n";
		}
		else
		{
			cout<<"wrong answer\n";
		}
		
		T--;
	}
	
	return	0;
}
