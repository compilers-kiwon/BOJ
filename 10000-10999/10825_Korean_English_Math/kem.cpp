#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_STUDENTS	(100000+1)

typedef	struct	_STUDENT_INFO	Student;
struct	_STUDENT_INFO
{
	string	name;
	int		korean,english,math;
};

bool	is_less(Student& s1,Student& s2)
{
	if( s1.korean > s2.korean )
	{
		return	true;
	}
	else if( s1.korean < s2.korean )
	{
		return	false;
	}
	
	if( s1.english < s2.english )
	{
		return	true;
	}
	else if( s1.english > s2.english )
	{
		return	false;
	}
	
	if( s1.math > s2.math )
	{
		return	true;
	}
	else if( s1.math < s2.math )
	{
		return	false;
	}
	
	if( s1.name < s2.name )
	{
		return	true;
	}
	
	return	false;
}

Student	student[MAX_NUM_OF_STUDENTS];

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>student[i].name>>student[i].korean>>student[i].english>>student[i].math;
	}
	
	sort(&student[1],&student[N+1],is_less);
	
	for(int i=1;i<=N;i++)
	{
		cout<<student[i].name<<'\n';
	}
	return	0;
}
