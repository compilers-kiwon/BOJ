#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(5000+1)
#define	MAX_WEIGHT	200000

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
	
typedef	pair<int,int>		Pair;
typedef	vector<Pair>		TwoPracel;

TwoPracel	weight_table[MAX_WEIGHT+MAX_WEIGHT+1];

int	main(void)
{
	int			w,n,A[MAX_SIZE];
	bool		visited[MAX_SIZE];
	
	cin.sync_with_stdio(false);
	
	cin>>w>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		visited[i] = false;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			weight_table[A[i]+A[j]].push_back(make_pair(i,j));
		}
	}
	
	for(int i=2;i<=MAX_WEIGHT+MAX_WEIGHT;i++)
	{
		if( weight_table[i].empty() )
		{
			continue;
		}
		
		int	target_weight;
		
		target_weight = w-i;
		
		if( IN_RANGE(1,target_weight,MAX_WEIGHT+MAX_WEIGHT) && !weight_table[target_weight].empty() )
		{
			TwoPracel&	first_pair = weight_table[i];
			TwoPracel&	second_pair = weight_table[target_weight];
			
			for(int j=0;j<first_pair.size();j++)
			{
				int&	first_pracel = first_pair[j].first;
				int&	second_pracel = first_pair[j].second;
				
				visited[first_pracel] = visited[second_pracel] = true;
					
				for(int k=0;k<second_pair.size();k++)
				{
					int&	third_pracel = second_pair[k].first;
					int&	fourth_pracel = second_pair[k].second;
					
					if( visited[third_pracel]==false && visited[fourth_pracel]==false )
					{
						cout<<"YES\n";
						return	0;
					}					
				}
				
				visited[first_pracel] = visited[second_pracel] = false;
			}
		}
	}
	
	cout<<"NO\n";
	return	0;
}
