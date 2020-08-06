#include	<iostream>
#include	<vector>
#include	<set>

using namespace	std;

#define	MAX_YEAR			5
#define	MAX_CLASS			9
#define	MAX_NUM_OF_STUDENT	(1000+1)

vector<int>	class_student[MAX_YEAR+1][MAX_CLASS+1];
set<int>	same_class_student[MAX_NUM_OF_STUDENT];
int			class_info[MAX_NUM_OF_STUDENT][MAX_YEAR+1];
int			N;

void	init(void)
{
	cin>>N;
	
	for(int student=1;student<=N;student++)
	{
		for(int year=1;year<=MAX_YEAR;year++)
		{
			int	class_no;
			
			cin>>class_no;
			
			class_student[year][class_no].push_back(student);
			class_info[student][year] = class_no;
		}
	}
}

void	find_same_class_student(void)
{
	for(int student=1;student<=N;student++)
	{
		for(int year=1;year<=MAX_YEAR;year++)
		{
			int class_no;
			
			class_no = class_info[student][year];
			
			vector<int>& this_student_class = class_student[year][class_no];
			
			for(int i=0;i<this_student_class.size();i++)
			{
				same_class_student[student].insert(this_student_class[i]);
			}
		}
	}
}

int		main(void)
{
	init();
	find_same_class_student();
	
	int	president_index,max_num_of_student;
	
	president_index = 1;
	max_num_of_student = same_class_student[1].size();
	
	for(int student=2;student<=N;student++)
	{
		if( max_num_of_student < same_class_student[student].size() )
		{
			max_num_of_student = same_class_student[student].size();
			president_index = student;
		}
	}
	cout<<president_index<<endl;
	
	return	0;
}
