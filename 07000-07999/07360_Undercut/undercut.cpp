#include	<iostream>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CARDS	(20+1)

typedef	pair<int,int>	Score;

void	get_score(int& A_card,int& B_card,int& A_score,int& B_score)
{
	int	diff;
	
	diff = abs(A_card-B_card);
	
	if( diff == 1 )
	{
		if( A_card < B_card )
		{
			A_score += A_card+B_card;
			
			if( A_card == 1 )
			{
				A_score += 3;
			}
		}
		else
		{
			B_score += A_card+B_card;
			
			if( B_card == 1 )
			{
				B_score += 3;
			}
		}
	}
	else
	{
		if( A_card > B_card )
		{
			A_score += A_card;
		}
		else
		{
			B_score += B_card;
		}
	}
}

int		main(void)
{
	vector<Score>	s;
	
	for(;;)
	{
		int	A[MAX_NUM_OF_CARDS],B[MAX_NUM_OF_CARDS];
		int	n,A_score,B_score;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		for(int i=1;i<=n;i++)
		{
			cin>>A[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			cin>>B[i];
		}
		
		A_score = B_score = 0;
		
		for(int i=1;i<=n;i++)
		{
			if( A[i] != B[i] )
			{
				get_score(A[i],B[i],A_score,B_score);
			}
		}
		
		s.push_back(make_pair(A_score,B_score));
	}
	
	for(int i=0;i<s.size()-1;i++)
	{
		cout<<"A has "<<s[i].first<<" points. B has "<<s[i].second<<" points.\n\n";
	}
	cout<<"A has "<<s.back().first<<" points. B has "<<s.back().second<<" points.\n";
	
	return	0;
}
