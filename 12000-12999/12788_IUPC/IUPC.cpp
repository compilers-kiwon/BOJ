#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	int	N,M,K;
	int	cnt,num_of_needed_pens,i;
	
	vector<int>	pens;
	
	cin>>N>>M>>K;
	
	for(i=1;i<=N;i++)
	{
		int	p;
		
		cin>>p;
		pens.push_back(p);
	}
	
	sort(pens.begin(),pens.end());
	
	num_of_needed_pens = M*K;
	
	for(i=pens.size()-1,cnt=0;i>=0 && num_of_needed_pens>0;i--,cnt++)
	{
		num_of_needed_pens -= pens[i];
	}
	
	if( num_of_needed_pens > 0 )
	{
		puts("STRESS");
	}
	else
	{
		cout<<cnt<<endl;
	}
	
	return	0;
}
