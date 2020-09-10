#include	<iostream>
#include	<string>

using namespace	std;

#define	get_index(c)		((int)((c)-'a'))
#define	mod(i)				((i)%26)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	decrypt(string& encrypted,int shift,string& table,string& decrypted)
{
	for(int i=0;i<encrypted.length();i++)
	{
		char&	c = encrypted[i];
		
		if( !IN_RANGE('a',c,'z') )
		{
			decrypted.push_back(c);
			continue;
		}
		
		int	index,shift_index;
		
		index = get_index(c);
		shift_index = mod(index+(26-shift));
		
		decrypted.push_back(table[shift_index]);
	}	
}

int		main(void)
{
	string	t;
	
	for(char c='a';c<='z';c++)
	{
		t.push_back(c);
	}
	
	for(;;)
	{
		int	d,m,y;
		
		cin>>d>>m>>y;
		getchar();
		
		if( d==0 && m==0 && y==0 )
		{
			break;
		}
		
		string	en,de;
				
		getline(cin,en);
		decrypt(en,(d+m+y)%25+1,t,de);
		
		cout<<de<<'\n';
	}
	
	return	0;
}
