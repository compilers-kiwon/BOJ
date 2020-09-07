#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(1000+1)

typedef	struct	_COURSE_INFO	Course;
struct	_COURSE_INFO
{
	string	day;
	int		begin_sec,end_sec;
};

#define	SEPARATOR_LEN	3
#define	SEC_PER_MIN		60
#define	SEC_PER_HOUR	60*SEC_PER_MIN

#define	convert_time_into_sec(hour,min)	((hour)*SEC_PER_HOUR+(min)*SEC_PER_MIN)

#define	TRUE	1
#define	FALSE	0

void	get_sec_time(string& str,Course& c)
{
	int	begin_hour,begin_min,end_hour,end_min;
	
	for(int pos=2;pos<str.length();pos+=SEPARATOR_LEN)
	{
		str[pos] = ' ';
	}
	
	sscanf(str.c_str(),"%d %d %d %d",&begin_hour,&begin_min,&end_hour,&end_min);
	
	c.begin_sec = convert_time_into_sec(begin_hour,begin_min);
	c.end_sec = convert_time_into_sec(end_hour,end_min);
}

void	parse_course(string& str,vector<string>& course_list)
{
	string	c;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			course_list.push_back(c);
			c.clear();
		}
		else
		{
			c.push_back(str[i]);
		}
	}
}

void	input(map<string,Course>& course,
			  vector<string>* student_course,
			  int& num_of_students)
{
	int	num_of_courses;
	
	cin>>num_of_courses>>num_of_students;
	
	for(int i=1;i<=num_of_courses;i++)
	{
		Course	c;
		
		string	name,time;
		string&	day = c.day;

		cin>>name>>day>>time;
		get_sec_time(time,c);
		
		course[name] = c;
	}
	
	getchar();
	
	for(int i=1;i<=num_of_students;i++)
	{
		string	str;
		
		getline(cin,str);
		parse_course(str,student_course[i]);
	}
}

int		is_overlapped(vector<string>& course_list,
					  map<string,Course>& course)
{
	for(int i=0;i<course_list.size()-1;i++)
	{
		for(int j=i+1;j<course_list.size();j++)
		{
			Course&	c1 = course[course_list[i]];
			Course&	c2 = course[course_list[j]];
			
			if( c1.day != c2.day )
			{
				continue;
			}
			
			if( c1.begin_sec == c2.begin_sec )
			{
				return	TRUE;
			}
			
			int	first_begin_time,first_end_time;
			int	second_begin_time,second_end_time;
			
			if( c1.begin_sec < c2.begin_sec )
			{
				first_begin_time = c1.begin_sec;
				first_end_time = c1.end_sec;
				
				second_begin_time = c2.begin_sec;
				second_end_time = c2.end_sec;
			}
			else
			{
				first_begin_time = c2.begin_sec;
				first_end_time = c2.end_sec;
				
				second_begin_time = c1.begin_sec;
				second_end_time = c1.end_sec;
			}
			
			if( first_end_time > second_begin_time )
			{
				return	TRUE;
			}
		}
	}
	
	return	FALSE;
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		map<string,Course>	course;
		vector<string>		student_course[MAX_SIZE];
		int					num_of_students;
		int					cnt_of_overlap;
		
		cnt_of_overlap = 0;
		input(course,student_course,num_of_students);
		
		for(int i=1;i<=num_of_students;i++)
		{
			cnt_of_overlap += is_overlapped(student_course[i],course);
		}
		
		cout<<"Data Set "<<k<<":\n"<<cnt_of_overlap<<'\n';
	}
	
	return	0;
}
