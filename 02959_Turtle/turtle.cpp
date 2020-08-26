#include	<iostream>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	int	line[4];
	
	cin>>line[0]>>line[1]>>line[2]>>line[3];
	
	sort(&line[0],&line[4]);
	
	cout<<min(line[0],line[1])*min(line[2],line[3])<<endl;
	
	return	0;
}
