#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))
#define	int2char(n)	((char)((n)+(int)'0'))

int	make_same_length(string& s1,string& s2)
{	
	if( s1.length() < s2.length() )
	{
		s1.insert(0,s2.length()-s1.length(),'0');
	}
	else
	{
		s2.insert(0,s1.length()-s2.length(),'0');
	}
	
	return	s1.length();
}

int	main(void)
{
	string	A,B,answer;
	int		len,carry,i;
	
	cin>>A>>B;
	
	len = make_same_length(A,B);
	
	for(i=len-1,carry=0;i>=0;i--)
	{
		int	a,b,tmp;
		
		a = char2int(A[i]);
		b = char2int(B[i]);
		tmp = a+b+carry;
		
		answer.insert(answer.begin(),int2char(tmp%10));
		carry = tmp/10;
	}
	
	if( carry == 1 )
	{
		answer.insert(answer.begin(),int2char(1));
	}
	
	cout<<answer<<endl;
	
	return	0;
}
