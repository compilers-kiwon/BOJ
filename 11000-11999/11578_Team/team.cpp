#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_QUIZ		(10+1)
#define	MAX_NUM_OF_STUDENT	(10+1)

int			quiz_info[MAX_NUM_OF_QUIZ];
vector<int>	quiz_can_be_solved[MAX_NUM_OF_STUDENT];
int			N,M;

bool	check_quiz_status(void)
{
	bool	result;
	int		i;
	
	for(result=true,i=1;i<=N;i++)
	{
		if( quiz_info[i] == 0 )
		{
			result = false;
			break;
		}
	}
	return	result;
}

void	find_team(int student_index,int& min_num_of_students,int current_num_of_students)
{
	if( student_index > M )
	{
		if( check_quiz_status() == true && current_num_of_students < min_num_of_students )
		{
			min_num_of_students = current_num_of_students;
		}
		return;
	}
	
	bool	flag;
	int		i;
	
	for(i=0,flag=false;i<quiz_can_be_solved[student_index].size();i++)
	{
		int	quiz_index = quiz_can_be_solved[student_index][i];
		
		if( quiz_info[quiz_index] == 0 )
		{
			flag = true;
			break;
		}
	}
	
	if( flag == true )
	{
		for(i=0;i<quiz_can_be_solved[student_index].size();i++)
		{
			int	quiz_index = quiz_can_be_solved[student_index][i];
			++quiz_info[quiz_index];
		}
		
		find_team(student_index+1,min_num_of_students,current_num_of_students+1);
		
		for(i=0;i<quiz_can_be_solved[student_index].size();i++)
		{
			int	quiz_index = quiz_can_be_solved[student_index][i];
			--quiz_info[quiz_index];
		}
	}
	
	find_team(student_index+1,min_num_of_students,current_num_of_students);
}

int		main(void)
{
	cin>>N>>M;
	
	int	i,min;
	
	for(i=1;i<=M;i++)
	{
		int	O,j;
		
		cin>>O;
		
		for(j=1;j<=O;j++)
		{
			int	P;
			
			cin>>P;
			quiz_can_be_solved[i].push_back(P);
		}
	}
	
	min = 0x7FFFFFFF;
	find_team(1,min,0);
	
	if( min == 0x7FFFFFFF )
	{
		min = -1;
	}
	
	cout<<min<<endl;
	
	return	0;
}
