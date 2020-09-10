#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'A'))
#define	int2char(n)	((char)((int)'A'+(n)))
#define	E(X)		((a*(X)+b)%26)
int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		a,b;
		string	s,encoded;
		
		cin>>a>>b>>s;
		
		for(int i=0;i<s.length();i++)
		{
			encoded.push_back(int2char(E(char2int(s[i]))));
		}
		cout<<encoded<<endl;
		
		T--;
	}
	return	0;
}
