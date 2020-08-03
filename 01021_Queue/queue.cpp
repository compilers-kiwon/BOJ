#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	N,M;
	vector<int>	rq;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		rq.push_back(i);
	}
	
	int	cnt = 0;
	
	for(int i=1;i<=M;i++)
	{
		int	n;
		
		cin>>n;
		
		if( rq[0] == n )
		{
			rq.erase(rq.begin());
		}
		else
		{
			int	n_pos;
			
			for(int i=0;i<rq.size();i++)
			{
				if( rq[i] == n )
				{
					n_pos = i;
					break;
				}
			}
			
			int	f_d,b_d;
			
			f_d = n_pos;
			b_d = rq.size()-n_pos;
			
			if( f_d < b_d )
			{
				while( rq[0] != n )
				{
					int tmp = rq[0];
					rq.erase(rq.begin());
					rq.push_back(tmp);
					cnt++;
				}
				rq.erase(rq.begin());
			}
			else
			{
				while( rq[0] != n )
				{
					int tmp = rq[rq.size()-1];
					rq.pop_back();
					rq.insert(rq.begin(),tmp);
					cnt++;
				}
				rq.erase(rq.begin());
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
