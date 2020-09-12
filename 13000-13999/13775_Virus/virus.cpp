#include	<iostream>
#include	<string>

using namespace	std;

#define	TABLE_SIZE			26
#define	KEY_SIZE			25
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	get_index(c)		((int)((c)-'a'))

int	main(void)
{
	char	table[TABLE_SIZE];
	int		K;
	string	encrypted;
	
	for(char c='a';c<='z';c++)
	{
		table[get_index(c)] = c;
	}
	
	cin>>K;getchar();
	getline(cin,encrypted);
	
	for(int i=0;i<encrypted.length();i++)
	{
		char&	c = encrypted[i];
		int		decrypted;
		
		if( IN_RANGE('a',c,'z') )
		{	
			if( K > KEY_SIZE )
			{
				K = 1;
			}		
			
			decrypted = get_index(c)-K;
			
			if( decrypted < 0 )
			{
				decrypted = TABLE_SIZE+decrypted;
			}
			
			c = table[decrypted];
			K++;
		}

		cout<<c;
	}
	cout<<'\n';
	
	return	0;
}
