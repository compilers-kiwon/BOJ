#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	10000
#define	int2char(n)	((char)((n)+(int)'0'))
	
int	N,end_num[MAX_SIZE+1];

void	int2str(int n,string& str)
{
	for(;n>0;n/=10)
	{
		str.push_back(int2char(n%10));	
	}
	
	for(int h=0,t=str.length()-1;h<t;h++,t--)
	{
		swap(str[h],str[t]);
	}
}

void	find_end_numbers(void)
{
	for(int ptr=1,n=666;ptr<=MAX_SIZE;n++)
	{
		string	str;
		
		int2str(n,str);
		
		for(int i=0;i<str.length()-2;i++)
		{
			if( str[i]=='6' && str[i+1]=='6' && str[i+2]=='6' )
			{
				end_num[ptr++] = n;
				break;
			}
		}
	}
}

int		main(void)
{
	cin>>N;
	
	find_end_numbers();
	cout<<end_num[N]<<'\n';
	
	return	0;
}
