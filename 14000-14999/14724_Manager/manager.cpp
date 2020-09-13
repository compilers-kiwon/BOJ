#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	NUM_OF_CIRCLE	9

void	get_representative_score(map<string,int>& table,string& name,int num_of_members)
{
	int	max_score,i;
	
	for(i=1,max_score=0;i<=num_of_members;i++)
	{
		int	s;
		
		cin>>s;
		max_score = max(max_score,s);
	}
	
	table[name] = max_score;
}

int		main(void)
{
	int				N;
	string			name[NUM_OF_CIRCLE] = {"PROBRAIN","GROW","ARGOS","ADMIN","ANT","MOTION","SPG","COMON","ALMIGHTY"};
	map<string,int>	max_score_table;
	
	cin>>N;
	
	for(int i=0;i<NUM_OF_CIRCLE;i++)
	{
		get_representative_score(max_score_table,name[i],N);
	}
	
	string	max_score_name;
	int		max_score;
	
	map<string,int>::iterator	iter;
	
	for(max_score=0,iter=max_score_table.begin();iter!=max_score_table.end();iter++)
	{
		if( iter->second > max_score )
		{
			max_score = iter->second;
			max_score_name = iter->first;
		}
	}
	cout<<max_score_name<<endl;
	
	return	0;	
}
