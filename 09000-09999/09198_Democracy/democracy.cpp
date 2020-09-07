#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

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

int	parse(string& s,int& ptr)
{
	vector<int>	vote;
	
	ptr++;
	
	for(bool flag=true;flag!=false;)
	{
		char&	c = s[ptr];
		
		switch(c)
		{
			case	'[':
				vote.push_back(parse(s,ptr));
				break;
			case	']':
				flag = false;
				ptr++;
				break;
			default:
				{
					string	n;
					
					for(;IN_RANGE('0',s[ptr],'9');ptr++)
					{
						n.push_back(s[ptr]);
					}
					
					vote.push_back(str2int(n)/2+1);
				}
				break;
		}
	}
	
	sort(vote.begin(),vote.end());
	
	int	win_number,ret;
	
	ret = 0;
	win_number = vote.size()/2+1;
	
	for(int i=0;i<win_number;i++)
	{
		ret += vote[i];
	}
	
	return	ret;	
}

int	main(void)
{
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	str;
		int		ptr;
		
		cin>>str;
		ptr = 0;
		
		cout<<parse(str,ptr)<<'\n';
	}
	
	return	0;
}
