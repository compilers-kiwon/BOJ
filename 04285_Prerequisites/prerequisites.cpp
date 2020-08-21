#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_CATEGORY	(100+1)
#define	MAX_SIZE		10000

bool	is_taken(vector<int>& course,vector<bool>& category,int required)
{
	int	cnt,i;
	
	for(cnt=i=0;i<course.size();i++)
	{
		if( category[course[i]] == true )
		{
			cnt++;
		}
	}
	
	return	(cnt>=required);
}

bool	input(int& num_of_categories,vector<int>& courses,
			  vector<bool>* category,int* required)
{
	int	k;
	
	cin>>k;
	
	if( k == 0 )
	{
		return	false;
	}
	
	cin>>num_of_categories;
	
	for(int i=1;i<=k;i++)
	{
		int	c;
		
		cin>>c;
		courses.push_back(c);
	}
	
	for(int i=1;i<=num_of_categories;i++)
	{
		int	c;
		
		cin>>c>>required[i];
		category[i].resize(MAX_SIZE,false);
		
		for(int j=1;j<=c;j++)
		{
			int	n;
			
			cin>>n;
			category[i][n] = true;
		}
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int				m,required[MAX_CATEGORY];
		vector<int>		course;
		vector<bool>	category[MAX_CATEGORY];
		bool			result;
		
		if( input(m,course,category,required) == false )
		{
			break;
		}
		
		result = true;
		
		for(int i=1;i<=m&&result==true;i++)
		{
			result = is_taken(course,category[i],required[i]);
		}
		
		if( result == true )
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	
	return	0;
}
