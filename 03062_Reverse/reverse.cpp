#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<utility>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))
#define	int2char(i)	((char)((i)+(int)'0'))

int		string2int(string str)
{
	int	value,i;
	
	for(value=0,i=0;i<str.length();i++)
	{
		value = value*10+char2int(str[i]);
	}
	return	value;
}

void	int2string(string& str,int n)
{
	for(;n>0;)
	{
		char	c;
		
		c = int2char(n%10);
		n = n/10;
		str.insert(str.begin(),c);
	}
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	N,R,S,answer;
		int		n,r,s;
		
		cin>>N;
		
		for(int i=N.length()-1;i>=0;i--)
		{
			R.push_back(N[i]);
		}
		
		n = string2int(N);
		r = string2int(R);
		s = n+r;
		int2string(S,s);
		
		answer = "YES\n";
		
		for(int head=0,tail=S.length()-1;head<tail;head++,tail--)
		{
			if( S[head] != S[tail] )
			{
				answer = "NO\n";
				break;
			}
		}
		cout<<answer;
		
		T--;	
	}
	
	return	0;
}
