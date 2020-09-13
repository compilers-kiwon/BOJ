#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_F_LEN	1001
#define	int2char(n)	((char)((n)+'0'))

void	div(int A,int B,string& answer)
{
	for(int len=1;len<=MAX_F_LEN;len++)
	{
		int	n;
		
		A *= 10;
		n = A/B;
		
		answer.push_back(int2char(n));
		
		if( (A=A%B) == 0 )
		{
			break;
		}
	}
}

int		main(void)
{
	string	f;
	int		A,B,n;
	
	cin>>A>>B;
	n = A/B;
	
	if( A%B == 0 )
	{
		cout<<n<<endl;;
	}
	else
	{
		div(A%B,B,f);
			cout<<n<<"."<<f<<endl;
	}
	
	return	0;
}
