#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_STUDENTS	(100+1)

typedef	pair<int,int>	Student;

struct	_STUDENT_INFO
{
	int	nation,number;
} student[MAX_NUM_OF_STUDENTS];

int	N,gold,silver,bronze;

priority_queue<Student>	sq;

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	s;
		
		cin>>student[i].nation>>student[i].number>>s;
		sq.push(make_pair(s,i));
	}
}

int		main(void)
{
	input();
	
	gold = sq.top().second;
	sq.pop();
	
	silver = sq.top().second;
	sq.pop();
	
	if( student[gold].nation == student[silver].nation )
	{
		while( student[sq.top().second].nation == student[gold].nation )
		{
			sq.pop();
		}
	}
	
	bronze = sq.top().second;
	
	cout<<student[gold].nation<<' '<<student[gold].number<<endl;
	cout<<student[silver].nation<<' '<<student[silver].number<<endl;
	cout<<student[bronze].nation<<' '<<student[bronze].number<<endl;
	
	return	0;
}
