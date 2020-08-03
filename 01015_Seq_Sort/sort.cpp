#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM	50

typedef	pair<int,int>	A_info;

bool	is_less(A_info& a,A_info& b)
{
	bool	result = false;
	
	if( a.first < b.first )
	{
		result = true;
	}
	else if( a.first > b.first )
	{
		result = false;
	}
	else
	{
		if( a.second < b.second )
		{
			result = true;
		}
	}
	
	return	result;
}

int		main(void)
{
	int		P[MAX_NUM];
	int		N,cnt;
	
	vector<A_info>	A_vector;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		int	A;
		
		cin>>A;
		A_vector.push_back(make_pair(A,i));
	}
	
	sort(A_vector.begin(),A_vector.end(),is_less);
	
	for(int i=0;i<N;i++)
	{
		int	P_index;
		
		P_index = A_vector[i].second;
		P[P_index] = i;
	}
	
	for(int i=0;i<N;i++)
	{
		cout<<P[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
