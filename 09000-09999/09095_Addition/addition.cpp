#include	<iostream>
#include	<set>
#include	<string>

using namespace std;

set<string>	cache;

void	count(int n,string& str)
{
	if( n == 0 )
	{
		cache.insert(str);
		return;
	}
	
	if( n>=1 )
	{
		string	new_str;
		count(n-1,(new_str=str+"1"));
	}
	
	if( n>=2 )
	{
		string	new_str;
		count(n-2,(new_str=str+"2"));
	}
	
	if( n>=3 )
	{
		string	new_str;
		count(n-3,(new_str=str+"3"));
	}
}

int	main(void)
{
	int	T,n;
	
	cin>>T;
	
	while(T>0)
	{
		cin>>n;
		
		string	exp;
		
		count(n,exp);
		cout<<cache.size()<<endl;
		cache.clear();
		
		T--;
	}
	return	0;
}
