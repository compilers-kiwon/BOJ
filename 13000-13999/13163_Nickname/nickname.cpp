#include	<iostream>
#include	<string>

using namespace	std;

void	print_god_name(string& str)
{
	int	i;
	
	for(i=0;str[i]!=' ';i++);
	
	cout<<"god";
	
	for(++i;i<str.length();i++)
	{
		if( str[i] != ' ' )
		{
			cout<<str[i];
		}
	}
	cout<<'\n';
	
	return;
}

int		main(void)
{
	int	N;
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		string	name;
		
		getline(cin,name);
		
		print_god_name(name);
	}
	
	return	0;
}
