#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_DISTANCE	26

int	main(void)
{
	string	str;
	int		sum;
	
	cin>>str;
	str.insert(str.begin(),'A');
	
	sum = 0;
	
	for(int i=1;i<str.length();i++)
	{
		char&	prev = str[i-1];
		char&	current = str[i];
		int		forward,backward;
		
		forward = max(prev,current)-min(prev,current);
		backward = MAX_DISTANCE-forward;
		
		sum += min(forward,backward);
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
