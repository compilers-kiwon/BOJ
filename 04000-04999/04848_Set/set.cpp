#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM	15

string	set_number[MAX_NUM+1];

void	build_set_number(void)
{
	set_number[0] = "{}";
	
	for(int i=1;i<=MAX_NUM;i++)
	{
		set_number[i].push_back('{');
		
		for(int j=0;j<i;j++)
		{
			set_number[i] += set_number[j]+",";
		}
		
		set_number[i][set_number[i].length()-1] = '}';
	}
}

int		main(void)
{
	build_set_number();
	
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		string	s1,s2;
		int		n1,n2;
		
		cin>>s1>>s2;
		
		for(n1=0;set_number[n1]!=s1;n1++);
		for(n2=0;set_number[n2]!=s2;n2++);
		
		cout<<set_number[n1+n2]<<'\n';
		
		T--;
	}
	
	return	0;
}
