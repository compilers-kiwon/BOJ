#include	<iostream>
#include	<string>
#include	<map>
#include	<algorithm>

using namespace	std;

void	init(map<string,int>& index)
{
	int		page_no;
	string	s;
	
	s = "abcdefghi";
	page_no = 1;
	
	do{
		index[s] = page_no++;
	}while(next_permutation(s.begin(),s.end()));
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N;
	map<string,int>	index;
	
	init(index);
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	w;
		
		cin>>w;
		cout<<index[w]<<'\n';
	}
	
	return	0;
}
