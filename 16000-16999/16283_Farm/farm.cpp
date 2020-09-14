#include <iostream>

using namespace std;

int main(void)
{
	int a,b,n,w;
	
	cin>>a>>b>>n>>w;
	
	int cnt,num_of_sheep,num_of_goat;
	pair<int,int> solution;
	
	for(num_of_sheep=1,cnt=0;num_of_sheep<n&&cnt<2;num_of_sheep++)
	{
		num_of_goat = n-num_of_sheep;
		
		if( a*num_of_sheep+b*num_of_goat == w )
		{
			cnt++;
			solution.first = num_of_sheep;
			solution.second = num_of_goat;
		}
	}
	
	if( cnt != 1 )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<solution.first<<' '<<solution.second<<'\n';
	}
	
	return 0;
}
