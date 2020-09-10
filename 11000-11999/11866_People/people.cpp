#include	<iostream>
#include	<string>

using namespace	std;

#define	int2char(n)	((char)(n)+'0')

int	main(void)
{
	int	N,M,current;
	
	cin>>N>>M;
	
	string	people;
	
	for(int i=0;i<N;i++)
	{
		people.push_back(int2char(i+1));
	}
	
	--M;
	current=0;
	
	cout<<'<';
	while( people.size() != 1 )
	{
		cout<<people[current=(current+M)%people.size()]<<", ";
		people.erase(current,1);
	}
	cout<<people[0]<<">\n";
	
	return	0;
}
