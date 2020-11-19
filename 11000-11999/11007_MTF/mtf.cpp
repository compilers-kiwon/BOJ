#include	<iostream>
#include	<string>

using namespace	std;

void	move_to_front(string& str,string& result,const int& index)
{
	char	c;
	
	c = str[index];
	result.push_back(c);
	
	str.erase(index,1);
	str.insert(str.begin(),c);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		string	str,result;
		int		n;
		
		cin>>n;
		str = "abcdefghijklmnopqrstuvwxyz";
		
		for(int i=1;i<=n;i++)
		{
			int	a;
			
			cin>>a;
			move_to_front(str,result,a);
		}
		
		cout<<result<<'\n';
	}
	
	return	0;
}
