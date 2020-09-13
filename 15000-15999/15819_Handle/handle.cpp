#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	int				N,I;
	vector<string>	dic;
	
	cin>>N>>I;
	
	for(int i=1;i<=N;i++)
	{
		string	str;
		
		cin>>str;
		dic.push_back(str);
	}
	
	sort(dic.begin(),dic.end());
	cout<<dic[I-1]<<'\n';
	
	return	0;	
}
