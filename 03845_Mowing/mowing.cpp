#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

bool	is_completed(vector<double>& v,double w,double max_value)
{
	bool	ret;
	double	prev;
	
	ret = true;
	prev = 0.0;
	
	for(int i=0;i<v.size();i++)
	{
		double	s,e;
		
		s = v[i]-w;
		e = v[i]+w;
		
		if( s > prev )
		{
			ret = false;
			break;
		}
		
		prev = e;
	}
	
	if( ret==true && prev<max_value )
	{
		ret = false;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		nx,ny;
		double	w;
		
		vector<double>	x,y;
		
		cin>>nx>>ny>>w;
		
		if( nx==0 && ny==0 && w==0.0 )
		{
			break;
		}
		
		for(int i=1;i<=nx;i++)
		{
			double	d;
			
			cin>>d;
			x.push_back(d);
		}
		
		for(int i=1;i<=ny;i++)
		{
			double	d;
			
			cin>>d;
			y.push_back(d);
		}
		
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		
		if( is_completed(x,w/2.0,75)==true && is_completed(y,w/2.0,100)==true )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return	0;
}
