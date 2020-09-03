#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

bool	is_included(string& former,string& later)
{
	int		i,len;
	bool	result;
	
	for(i=0,len=former.length(),result=true;i<len;i++)
	{
		if( former[i] != later[i] )
		{
			result = false;
			break;
		}
	}
	return	result;
}

bool	find_consistency(vector<string>& list)
{
	int		i,size;
	bool	result;
	
	for(i=0,size=list.size(),result=true;i<size-1;i++)
	{
		if( is_included(list[i],list[i+1]) == true )
		{
			result = false;
			break;
		}
	}
	return	result;	
}

int		main(void)
{
	int	t;
	
	scanf("%d\n",&t);
	
	while(t>0)
	{
		vector<string>	phone_number;
		int				n,i;
		
		scanf("%d",&n);
		
		for(i=1;i<=n;i++)
		{
			string	number;
			
			cin>>number;
			phone_number.push_back(number);
		}
		
		sort(phone_number.begin(),phone_number.end());
		
		for(i=0;i<phone_number.size();i++)
		{
			cout<<phone_number[i]<<endl;
		}
		if( find_consistency(phone_number) == true )
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
		
		t--;
	}
	return	0;
 }
