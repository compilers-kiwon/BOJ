#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

string		N;
vector<int>	n;

int	main(void)
{
	cin>>N;
	
	int	num_of_zero = 0;
	
	for(int i=0;i<N.length();i++)
	{
		if( N[i] == '0' )
		{
			++num_of_zero;
		}
		n.push_back(char2int(N[i]));
	}
	
	if( num_of_zero == 0 )
	{
		cout<<-1<<endl;
		return	0;
	}
	
	int	sum = 0;
	
	for(int i=0;i<n.size();i++)
	{
		sum += n[i];
	}
	
	if( sum == 0 || sum%3 != 0 )
	{
		cout<<-1<<endl;
		return	0;
	}
	
	sort(n.begin(),n.end());
	
	for(int i=n.size()-1;i>=0;i--)
	{
		cout<<n[i];
	}
	cout<<endl;
	
	return	0;
}
