#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	GET_ANSWER_INDEX(i,n)	((i)%(n))

typedef	pair<string,int>	Paper;

int	main(void)
{
	int					N,max_score;
	string				answer;
	map<string,Paper>	student;
	
	cin>>N>>answer;
	
	student["Adrian"] = make_pair("ABC",0);
	student["Bruno"] = make_pair("BABC",0);
	student["Goran"] = make_pair("CCAABB",0);
	
	max_score = 0;
	
	map<string,Paper>::iterator	it;
	
	for(int i=0;i<N;i++)
	{
		char&	current_answer = answer[i];
		
		for(it=student.begin();it!=student.end();it++)
		{
			string&	student_answer = it->second.first;
			
			if( current_answer == student_answer[GET_ANSWER_INDEX(i,student_answer.length())] )
			{
				it->second.second++;
				
				if( it->second.second > max_score )
				{
					max_score = it->second.second;
				}
			}
		}
	}
	
	cout<<max_score<<'\n';
	
	for(it=student.begin();it!=student.end();it++)
	{
		if( it->second.second == max_score )
		{
			cout<<it->first<<'\n';
		}
	}
	
	return	0;
}
