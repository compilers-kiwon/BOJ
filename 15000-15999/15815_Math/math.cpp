#include	<iostream>
#include	<stack>
#include	<string>

using namespace	std;

#define	ADD	'+'
#define	SUB	'-'
#define	MUL	'*'
#define	DIV	'/'

#define	char2int(c)		((int)((c)-'0'))
#define	get_num(a,st)	(a)=(st).top();(st).pop();

int	main(void)
{
	string		exp;
	stack<int>	n;
	
	cin>>exp;
	
	for(int i=0;i<exp.length();i++)
	{
		char&	c = exp[i];
		int		a,b;
		
		switch(c)
		{
			case	ADD:
				get_num(a,n);
				get_num(b,n);
				n.push(a+b);
				break;
			case	SUB:
				get_num(a,n);
				get_num(b,n);
				n.push(b-a);
				break;	
			case	MUL:
				get_num(a,n);
				get_num(b,n);
				n.push(a*b);
				break;
			case	DIV:
				get_num(a,n);
				get_num(b,n);
				n.push(b/a);
				break;
			default:
				n.push(char2int(c));
				break;	
		}
	}
	cout<<n.top()<<endl;
	
	return	0;
}
