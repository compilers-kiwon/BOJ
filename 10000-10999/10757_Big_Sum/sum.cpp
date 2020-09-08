#include	<iostream>
#include	<string>

using namespace	std;

#define	int2char(n)	('0'+(char)(n))
#define	char2int(c)	((int)(c-'0'))

string	A,B,sum;

void	input(void)
{
	cin>>A>>B;
	
	if( A.length() < B.length() )
	{
		int	diff = B.length()-A.length();
		
		for(int i=1;i<=diff;i++)
		{
			A.insert(0,"0");
		}
	}
	else
	{
		int	diff = A.length()-B.length();
		
		for(int i=1;i<=diff;i++)
		{
			B.insert(0,"0");
		}
	}
}

void	big_sum(int index,int carry)
{
	if( index == -1 )
	{
		if( carry != 0 )
		{
			sum.insert(sum.begin(),int2char(carry));
		}
		return;
	}
	
	int	a,b,tmp;
	
	a = char2int(A[index]);
	b = char2int(B[index]);
	tmp = a+b+carry;
	
	sum.insert(sum.begin(),int2char(tmp%10));
	
	return	big_sum(index-1,tmp/10);
}

int		main(void)
{
	input();
	big_sum(A.length()-1,0);
	cout<<sum<<endl;
	
	return	0;
}
