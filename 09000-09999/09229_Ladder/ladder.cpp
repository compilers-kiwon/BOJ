#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

bool	is_ladder(const string s1,const string& s2)
{
	if( s1.length() != s2.length() )
	{
		return	false;
	}
	
	int	cnt_of_difference;
	
	cnt_of_difference = 0;
	
	for(int i=0;i<s1.length();i++)
	{
		if( s1[i] != s2[i] )
		{
			cnt_of_difference++;
		}
	}
	
	return	(cnt_of_difference==1);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string			w;
		bool			result;
		vector<string>	words;
		
		cin>>w;
		
		if( w == "#" )
		{
			break;
		}
		
		words.push_back(w);
		
		for(;;)
		{
			cin>>w;
		
			if( w == "#" )
			{
				break;
			}
			
			words.push_back(w);
		}
		
		result = true;
		
		for(int i=0;i<words.size()-1&&result==true;i++)
		{
			result = is_ladder(words[i],words[i+1]);
		}
		
		if( result == true )
		{
			cout<<"Correct\n";
		}
		else
		{
			cout<<"Incorrect\n";
		}
	}
	
	return	0;
}
