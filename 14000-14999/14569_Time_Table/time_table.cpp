#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_COURSE	(1000+1)
#define	NUM_OF_DAYS			5
#define	MAX_TIME			50

#define	GET_DAY(n)	((n)/10)
#define	GET_TIME(n)	((n)%10)

#define	TRUE	1
#define	FALSE	0

vector<int>	course[MAX_NUM_OF_COURSE];

void	get_course_info(int num_of_course)
{
	for(int i=1;i<=num_of_course;i++)
	{
		int	k;
		
		cin>>k;
		
		for(int j=1;j<=k;j++)
		{
			int	t;
			
			cin>>t;
			course[i].push_back(t);
		}
	}
}

int		is_available(vector<bool>& student_available,int course_index)
{
	int				result;
	vector<int>&	course_time = course[course_index];
	
	result = TRUE;
	
	for(int i=0;i<course_time.size();i++)
	{
		if( student_available[course_time[i]] == false )
		{
			result = FALSE;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int	N,M;
	
	cin>>N;
	get_course_info(N);
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		vector<bool>	student_time_table(MAX_TIME+1,false);
		int				p,q,cnt;
		
		cin>>p;
		cnt = 0;
		
		for(int i=1;i<=p;i++)
		{
			cin>>q;
			student_time_table[q] = true;
		}
		
		for(int i=1;i<=N;i++)
		{
			cnt += is_available(student_time_table,i);
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
