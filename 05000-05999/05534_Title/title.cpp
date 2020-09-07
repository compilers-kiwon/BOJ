#include	<iostream>
#include	<string>

using namespace	std;

bool	can_be_reused(string& title,int title_index,string& prev,int prev_index,int diff)
{
	if( title_index == title.length() )
	{
		return	true;
	}
	
	bool	result;
	
	if( prev_index<prev.length() && title[title_index]==prev[prev_index] )
	{
		return	can_be_reused(title,title_index+1,prev,prev_index+diff,diff); 
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,cnt;
	string	my;
	
	cin>>N>>my;
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		string	prev;
		int		max_offset;
		bool	result;
		
		cin>>prev;
		result = false;
		max_offset = (prev.length()-1)/(my.length()-1);
		
		for(int j=0;j<prev.length()&&result==false;j++)
		{
			for(int k=1;k<=max_offset&&result==false;k++)
			{
				if( prev.length()-1-j>=k*(my.length()-1) )
				{
					result = can_be_reused(my,0,prev,j,k);
				}
			}
		}
		
		if( result == true )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
