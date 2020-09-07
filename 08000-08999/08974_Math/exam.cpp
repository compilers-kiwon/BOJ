#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	vector<int>	seq;
	int			A,B,sum;
	
	cin>>A>>B;
	seq.push_back(0);
		
	for(int i=1;seq.size()<=B;i++)
	{
		for(int j=1;j<=i;j++)
		{
			seq.push_back(i);
		}
	}
	
	sum = 0;
	
	for(int i=A;i<=B;i++)
	{
		sum += seq[i];
	}
	cout<<sum<<endl;
	
	return	0;
}
