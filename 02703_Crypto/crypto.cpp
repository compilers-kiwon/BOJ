#include	<iostream>
#include	<string>

using namespace	std;

#define	GET_INDEX(c)	((int)((c)-'A'))

int	main(void)
{
	int	T;
	
	cin>>T;getchar();
	
	while(T>0)
	{
		string	encrypt,decrypt,code;
		
		getline(cin,encrypt);
		cin>>code;getchar();
		
		for(int i=0;i<encrypt.length();i++)
		{
			char&	c = encrypt[i];
			
			if( c != ' ' )
			{
				decrypt.push_back(code[GET_INDEX(c)]);
			}
			else
			{
				decrypt.push_back(' ');
			}
		}
		decrypt.push_back('\n');
		
		cout<<decrypt;
		T--;
	}
	return	0;
}
