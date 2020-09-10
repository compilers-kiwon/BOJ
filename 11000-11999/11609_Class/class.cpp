#include	<iostream>
#include	<algorithm>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_STUDENTS	(100+1)

typedef	pair<string,string>	Name;	

int	main(void)
{
	int		n;
	Name	s[MAX_NUM_OF_STUDENTS];
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].second>>s[i].first;
	}
	
	sort(&s[1],&s[n+1]);
	
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].second<<' '<<s[i].first<<'\n';	
	}
	
	return	0;
}	
