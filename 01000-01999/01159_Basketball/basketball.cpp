#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	int				N;
	map<char,int>	family_name;
	
	for(char c='a';c<='z';c++)
	{
		family_name[c] = 0;
	}
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string name;
		
		cin>>name;
		family_name[name[0]]++;
	}
	
	string	answer;
	
	for(char c='a';c<='z';c++)
	{
		if( family_name[c] >= 5 )
		{
			answer.push_back(c);
		}
	}
	
	if( answer.length() == 0 )
	{
		cout<<"PREDAJA\n";
	}
	else
	{
		cout<<answer<<endl;
	}
	return	0;
}
