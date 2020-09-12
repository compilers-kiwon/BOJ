#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(200000+1)

int			C,P,X,L;
int			initial_partner_cnt[MAX_SIZE];
int			left_partner_cnt[MAX_SIZE];
vector<int>	partner[MAX_SIZE];

void	input(void)
{
	cin>>C>>P>>X>>L;
	
	for(int i=1;i<=P;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		partner[A].push_back(B);
		initial_partner_cnt[A]++;
		
		partner[B].push_back(A);
		initial_partner_cnt[B]++;
	}
}

bool	will_stay(void)
{
	queue<int>		leave_q;
	vector<bool>	is_left(C+1,false);
	
	leave_q.push(L);
	is_left[L] = true;
	
	for(;!leave_q.empty();)
	{
		int	left_country;
		
		left_country = leave_q.front();
		leave_q.pop();
		
		if( left_country == X )
		{
			return	false;
		}
		
		vector<int>	my_partner = partner[left_country];
		
		for(int i=0;i<my_partner.size();i++)
		{
			int&	p = my_partner[i];
			
			if( is_left[p] == true )
			{
				continue;
			}
			
			left_partner_cnt[p]++;
			
			if( initial_partner_cnt[p] <= left_partner_cnt[p]*2 )
			{
				is_left[p] = true;
				leave_q.push(p);
			}
		} 
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	if( will_stay() == true )
	{
		cout<<"stay\n";
	}
	else
	{
		cout<<"leave\n";
	}
	
	return	0;
}
