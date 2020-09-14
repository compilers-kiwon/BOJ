#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SUB	(25+1)

int				N;
vector<string>	all_features;
vector<string>	subs[MAX_SUB];

void	add_feature_to_all(string& feature)
{
	bool	found;
	int		i;
	
	for(i=0,found=false;i<all_features.size();i++)
	{
		if( all_features[i] == feature )
		{
			found = true;
			break;
		}
	}
	
	if( found == false )
	{
		all_features.push_back(feature);
	}
}

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	K;
		
		cin>>K;
		
		for(int j=1;j<=K;j++)
		{
			string	feature;
			
			cin>>feature;
			subs[i].push_back(feature);
			
			add_feature_to_all(feature);
		}
	}
}

bool	is_mutually_exclusive(string& f1,string& f2)
{
	bool	f1_only,f2_only,both_of_f1_and_f2,ret;
	
	f1_only = f2_only = both_of_f1_and_f2 = false;
	
	for(int i=1;i<=N;i++)
	{
		vector<string>& my_features = subs[i];
		bool			f1_found,f2_found;
		
		f1_found = f2_found = false;
		
		for(int j=0;j<my_features.size();j++)
		{
			if( my_features[j] == f1 )
			{
				f1_found = true;
			}
			
			if( my_features[j] == f2 )
			{
				f2_found = true;
			}
		}
		
		if( f1_found==true && f2_found==true )
		{
			both_of_f1_and_f2 = true;
		}
		else if( f1_found == true )
		{
			f1_only = true;
		}
		else if( f2_found == true )
		{
			f2_only = true;
		}
	}
	
	if( both_of_f1_and_f2==true && f1_only==true && f2_only==true )
	{
		ret = false;
	}
	else
	{
		ret = true;
	}
	
	return	ret;
}

int		main(void)
{
	input();
	
	bool	mutually_exclusive_flag;
	
	mutually_exclusive_flag = true;
	
	for(int i=0;i<all_features.size()-1&&mutually_exclusive_flag==true;i++)
	{
		for(int j=i+1;j<all_features.size()&&mutually_exclusive_flag==true;j++)
		{
			mutually_exclusive_flag = is_mutually_exclusive(all_features[i],all_features[j]);
		}
	}
	
	if( mutually_exclusive_flag == true )
	{
		cout<<"yes\n";
	}
	else
	{
		cout<<"no\n";
	}
	
	return	0;
}
