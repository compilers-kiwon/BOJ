#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	struct	_STUDENT	Student;
struct	_STUDENT
{
	string	name;
	int		d,m,y;
};

bool	is_earlier(int& a,int& b)
{
	return	a<b;
}

bool	is_older(Student& a,Student& b)
{
	bool	result;
	
	if( a.y != b.y )
	{
		result = is_earlier(a.y,b.y);
	}
	else
	{
		if( a.m != b.m )
		{
			result = is_earlier(a.m,b.m);	
		}
		else
		{
			result = is_earlier(a.d,b.d);	
		}	
	}
	return	result; 
}

int		main(void)
{
	vector<Student> s;
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		Student	t;
		
		cin>>t.name>>t.d>>t.m>>t.y;
		s.push_back(t);
	}
	sort(s.begin(),s.end(),is_older);
	
	cout<<s[n-1].name<<endl;cout<<s[0].name<<endl;
	
	return	0;
}
