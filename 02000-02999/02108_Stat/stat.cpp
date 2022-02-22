#include	<iostream>
#include	<algorithm>
#include	<cmath>
#include	<vector>
#include	<map>

using namespace	std;

int	main(void)
{
	int				N,sum;
	vector<int>		num;
	map<int,int>	count_table;

	cin>>N;
	sum = 0;

	for(int i=1;i<=N;i++)
	{
		int	n;

		cin>>n;
		sum += n;

		num.push_back(n);
		count_table[n]++;
	}

	cout<<(int)round((double)sum/(double)N)<<'\n';

	sort(num.begin(),num.end());
	cout<<num[N/2]<<'\n';

	int			max_cnt = 0;
	vector<int>	mode;

	for(map<int,int>::iterator it=count_table.begin();it!=count_table.end();it++)
	{
		if( it->second >= max_cnt )
		{
			if( it->second > max_cnt )
			{
				mode.clear();
			}

			max_cnt = it->second;
			mode.push_back(it->first);
		}
	}

	cout<<(mode.size()==1?mode[0]:mode[1])<<'\n';
	cout<<num.back()-num.front()<<'\n';

	return	0;
}