#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

void	solve(vector<int>& answer)
{
	int			M,n;
	vector<int>	numbers;
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		vector<int>::iterator	it;
		
		cin>>n;
		
		it = lower_bound(numbers.begin(),numbers.end(),n);
		numbers.insert(it,n);
		
		if( i%2 != 0 )
		{
			answer.push_back(numbers[i/2]);
		}
	}
}

void	print(vector<int>& answer)
{
	cout<<answer.size()<<endl;
	
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<' ';
		
		if( i%10 == 9 )
		{
			cout<<'\n';
		}
	}
	cout<<'\n';
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		vector<int>	answer;
		
		solve(answer);
		print(answer);
		
		T--;
	}
	
	return	0;
}
