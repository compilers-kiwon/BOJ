#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<map>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))
#define	int2char(i)	((char)((char)(i)+'0'))

void	reverse_str(string& str)
{
	for(int h=0,t=str.length()-1;h<t;h++,t--)
	{
		swap(str[h],str[t]);
	}
}

void	int2str(int n,string& s,int len)
{
	for(;n>0;n/=10)
	{
		s.push_back(int2char(n%10));
	}
	
	for(int i=s.length();i<len;i++)
	{
		s.push_back('0');
	}
}

int		str2int(string& str)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+char2int(str[i]);
	}
	
	return	ret;
}

void	get_numbers(string& n,int& min_num,int& max_num)
{
	sort(n.begin(),n.end());
	min_num = str2int(n);
	
	reverse_str(n);
	max_num = str2int(n);
}

int		main(void)
{
	for(;;)
	{
		int				a,L;
		map<int,int>	visited;
		
		cin>>a>>L;
		
		if( a==0 && L==0 )
		{
			break;
		}
		
		visited[a] = 1;
		
		for(int i=2;;i++)
		{
			string	number;
			int		min_num,max_num,value;
			
			int2str(a,number,L);
			get_numbers(number,min_num,max_num);
			
			value = max_num-min_num;
			
			if( visited[value] != 0 )
			{
				cout<<visited[value]-1<<' '<<value<<' '<<i-visited[value]<<'\n';
				break;
			}
			
			visited[value] = i;
			a = value;
		}
	}
	
	return	0;
}
