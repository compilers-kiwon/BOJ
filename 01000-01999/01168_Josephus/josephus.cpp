#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int			N,M,index_to_be_removed;
	vector<int>	people;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		people.push_back(i);
	}
	
	cout<<'<';
	
	for(index_to_be_removed=0;people.size()!=1;)
	{
		index_to_be_removed = (index_to_be_removed+M-1)%people.size();
		
		cout<<people[index_to_be_removed]<<", ";
		people.erase(people.begin()+index_to_be_removed);
	}
	cout<<people[0]<<">\n";
	
	return	0;
}
