#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE			(100+1)
#define	OFFSET				0x20
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		n;
string	building[MAX_SIZE],code;

void	input(void)
{
	cin>>n;
	getchar();
	
	for(int i=1;i<=n;i++)
	{
		getline(cin,building[i]);
	}
	
	cin>>code;
}

bool	compare_char(char c1,char c2)
{
	if( IN_RANGE('a',c1,'z') == true )
	{
		c1 -= OFFSET;
	}
	
	if( IN_RANGE('a',c2,'z') == true )
	{
		c2 -= OFFSET;
	}
	
	return	(c1==c2);
}

bool	find_code(string& name,string& code)
{
	int		code_ptr;
	
	code_ptr = 0;
	
	for(int i=0;i<name.length()&&code_ptr<code.length();i++)
	{
		if( name[i] == ' ' )
		{
			continue;
		}
		
		if( compare_char(name[i],code[code_ptr]) == true )
		{
			code_ptr++;
		}
	}
	
	return	(code_ptr==code.length());
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		input();
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=1;i<=n;i++)
		{
			if( find_code(building[i],code) == true )
			{
				cout<<building[i]<<'\n';
			}
		}
		
		cout<<'\n';
	}
	
	return	0;
}
