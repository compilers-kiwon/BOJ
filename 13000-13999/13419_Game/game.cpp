#include	<iostream>
#include	<vector>

using namespace	std;

void	get_pattern(int s,int len,string& str,string& p)
{
	for(int i=s%len;p.find(str[i],0)==p.npos;i=(i+2)%len)
	{
		p.push_back(str[i]);
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	str,p1,p2;
		int		len;
		
		cin>>str;
		len = str.length();
		
		get_pattern(0,len,str,p1);
		get_pattern(1,len,str,p2);
		
		cout<<p1<<endl<<p2<<endl;
		
		T--;
	}
	return	0;
}
