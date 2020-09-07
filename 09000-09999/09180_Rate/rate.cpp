#include	<iostream>
#include	<cmath>
#include	<vector>
#include	<cfloat>

using namespace	std;

typedef	pair<double,double>	Investment;

#define	MAX_RATE	99999

bool	input(int& num_of_investments,vector<Investment>& in,Investment& result)
{
	double	month,money;
		
	cin>>num_of_investments;
	
	if( num_of_investments == -1 )
	{
		return	false;
	}
	
	for(int i=1;i<=num_of_investments;i++)
	{	
		cin>>month>>money;
		in.push_back(make_pair(month,money));
	}
	
	cin>>month>>money;
	result = make_pair(month,money);
	
	return	true;
}

double		get_result(double rate,vector<Investment>& in,double end_month)
{
	double	ret;
	int		i;
	
	for(ret=0.0,i=0;i<in.size();i++)
	{
		double&	month = in[i].first;
		double&	money = in[i].second;
		
		ret += money*pow(1.00+rate,end_month-month+1.0);
	}
	
	return	ret;
}

int		main(void)
{
	for(int c=1;;c++)
	{
		int					N;
		vector<Investment>	in;
		Investment			e;
		double				rate;
		
		if( input(N,in,e) == false )
		{
			break;
		}
		
		double	prev_diff,current_diff;
		
		prev_diff = DBL_MAX;
		
		for(double r=0.00001;r<1.0;r+=0.00001)
		{
			current_diff = e.second-get_result(r,in,e.first);
			
			if( abs(current_diff) >= abs(prev_diff) )
			{
				break;
			}
			
			prev_diff = current_diff;
			rate = r;
		}
		
		if( rate == 0.00001 )
		{
			rate = 0.0;
		}
		
		printf("Case %d: %.5f\n\n",c,rate);
	}
	
	return	0;
}
