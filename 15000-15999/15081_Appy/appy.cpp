#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

int	pick_app(vector<string>& app_list,map<string,bool>& picked_already)
{
	int	idx;
	
	for(idx=0;idx<app_list.size();idx++)
	{
		if( picked_already[app_list[idx]] == false )
		{
			picked_already[app_list[idx]] = true;
			break;
		}
	}
	
	return	idx;
}

int	main(void)
{
	int					n;
	map<string,bool>	picked_already;
	string				picked_list;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int				m,my_app;
		vector<string>	apps;
		
		cin>>m;
		
		for(int j=1;j<=m;j++)
		{
			string	a;
			
			cin>>a;
			apps.push_back(a);
		}
		
		my_app = pick_app(apps,picked_already);
		
		if( my_app < apps.size() )
		{
			picked_list += apps[my_app]+" ";
		}
	}
	
	picked_list[picked_list.length()-1] = '\n';
	cout<<picked_list;
	
	return	0;
}
