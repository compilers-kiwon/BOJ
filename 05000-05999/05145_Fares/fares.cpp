#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_NUM_OF_STOPS	50

void	input(map<string,int>& stations,
			  int* price,string& from,string& to)
{
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n-1;i++)
	{
		cin>>price[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		string	s;
		
		cin>>s;
		stations[s] = i;
	}
	
	cin>>from>>to;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		string			from,to;
		map<string,int>	stations;
		int				price[MAX_NUM_OF_STOPS];
		int				diff;
		
		input(stations,price,from,to);
		diff = max(stations[from],stations[to])
				- min(stations[from],stations[to]);
				
		cout<<"Data Set "<<k<<":\n"<<price[diff]<<"\n\n";
	}
	
	return	0;
}
