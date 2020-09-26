#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0xFF
#define	char2int(c)	((int)((c)-'0'))
#define	END			' '

#define	ATOM	0
#define	NUMBER	1

int	input[MAX_SIZE],num,output[MAX_SIZE];

int	str2int(string& str)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+char2int(str[i]);
	}
	
	return	ret;
}

void	parse(string& str,int* result)
{
	int		required;
	char	a;
	string	num;
	
	required = ATOM;
	
	for(int i=0;i<str.length();)
	{
		switch(required)
		{
			case	ATOM:
				a = str[i++];
				required = NUMBER;
				break;
			case	NUMBER:
				for(;str[i]>='0'&&str[i]<='9';i++)
				{
					num.push_back(str[i]);
				}
				
				if( num.empty() )
				{
					result[a] += 1;
				}
				else
				{
					result[a] += str2int(num);
				}
				
				num.clear();
				required = ATOM;
				 
				break;
			default:
				// do nothing
				break;
		}
	}
}

int		main(void)
{
	string	m1,m2;
	int		n;
	
	n = 0x7FFFFFFF;
	cin>>m1>>num>>m2;
	
	m1.push_back(END);
	m2.push_back(END);
	
	parse(m1,input);
	parse(m2,output);
	
	for(char c='A';c<='Z';c++)
	{
		if( output[c] != 0 )
		{
			n = min(n,input[c]*num/output[c]);
		}
	}
	
	cout<<n<<'\n';
	
	return	0;
}
