#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	DELIMITER			','
#define	MAX_NUM_OF_PROBLEMS	(20+1)
#define	MAX_NUM_OF_TEAMS	(50+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_TEAM_INFO	Team;
struct	_TEAM_INFO
{
	string	name,upper_alpahbet_name;
	int		rank,score;	
};

bool	is_solved(string& str)
{
	int	i;
	
	for(i=0;str[i]!='/';i++);
	i++;
	
	return	(str[i]!='-');
}

void	get_team_name(string& input,int& index,Team& t)
{
	for(;input[index]!=DELIMITER;index++)
	{
		char&	c = input[index];
		
		t.name.push_back(c);
		
		if( IN_RANGE('a',c,'z') )
		{
			t.upper_alpahbet_name.push_back(c-32);
		}
		else
		{
			t.upper_alpahbet_name.push_back(c);	
		}	
	}
	
	index++;	
}

void	get_score(string& input,int& index,Team& t,int* problem_score)
{
	string	buf;
	
	for(int problem_index=1;index<input.length();index++)
	{
		char&	c = input[index];
		
		if( c == DELIMITER )
		{
			int		time;
			
			if( is_solved(buf) == true )
			{
				t.score += problem_score[problem_index];
			}
			
			problem_index++;
			buf.clear();
		}
		else
		{
			buf.push_back(c);
		}
	}
}

bool	is_higher(const Team& t1,const Team& t2)
{
	bool	result;
	
	if( t1.score > t2.score )
	{
		result = true;
	}
	else
	{
		if( t1.score < t2.score )
		{
			result = false;
		}
		else
		{
			if( t1.upper_alpahbet_name < t2.upper_alpahbet_name )
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
	}
	
	return	result;
}

int		main(void)
{
	for(int c=1;;c++)
	{
		int	P;
		
		cin>>P;
		
		if( P == 0 )
		{
			break;
		}
		
		int		problem_score[MAX_NUM_OF_PROBLEMS],T;
		Team	t[MAX_NUM_OF_TEAMS];
		
		for(int i=1;i<=P;i++)
		{
			cin>>problem_score[i];
		}
		
		cin>>T;getchar();
		
		for(int i=1;i<=T;i++)
		{
			string	record;
			int		record_index;
			
			getline(cin,record);
			
			record.push_back(DELIMITER);
			record_index = 0;
			
			t[i].score = 0;
			
			get_team_name(record,record_index,t[i]);
			get_score(record,record_index,t[i],problem_score);
		}
		
		sort(&t[1],&t[T+1],is_higher);
		
		t[1].rank = 1;
		
		for(int i=2;i<=T;i++)
		{
			if( t[i].score == t[i-1].score )
			{
				t[i].rank = t[i-1].rank;
			}
			else
			{
				t[i].rank = i;
			}
		}
		
		cout<<"Contest "<<c<<'\n';
		
		for(int i=1;i<=T;i++)
		{
			cout<<t[i].rank<<' '<<t[i].name<<' '<<t[i].score<<'\n';
		}
	}
	
	return	0;
}
