#include	<iostream>
#include	<string>
#include	<set>

using namespace std;

set<string>	possible_answers[2];
int			current_set;

void	init_possible_answers(void)
{
	char	c1,c2,c3;
	
	for(c1='1';c1<='9';c1++)
	{
		for(c2='1';c2<='9';c2++)
		{
			if( c2 == c1 )
			{
				continue;
			}
			
			for(c3='1';c3<='9';c3++)
			{
				if( c3 == c1 || c3 == c2 )
				{
					continue;
				}
				
				string	str;
				
				str.push_back(c1);
				str.push_back(c2);
				str.push_back(c3);
				
				possible_answers[current_set].insert(str);
			}
		}
	}
}

int		main(void)
{
	int	N,i;
	
	current_set = 0;
	init_possible_answers();
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		string	str;
		int		strike,ball,s_cnt,b_cnt;
				
		cin>>str>>strike>>ball;
		
		set<string>::iterator	si;
		
		for(si=possible_answers[current_set].begin();si!=possible_answers[current_set].end();si++)
		{
			s_cnt = b_cnt = 0;
			
			for(int j=0;j<3;j++)
			{
				if( str[j] == (*si)[j] )
				{
					s_cnt++;
				}
			}
						
			if( str[0] == (*si)[1] || str[0] == (*si)[2] )
			{
				b_cnt++;
			}
			
			if( str[1] == (*si)[0] || str[1] == (*si)[2] )
			{
				b_cnt++;
			}
			
			if( str[2] == (*si)[0] || str[2] == (*si)[1] )
			{
				b_cnt++;
			}
			
			if( s_cnt==strike && b_cnt==ball )
			{
				possible_answers[(current_set+1)%2].insert(*si);
				continue;
			}
		}
		
		possible_answers[current_set].clear();
		current_set = (current_set+1)%2;
		
		for(si=possible_answers[current_set].begin();si!=possible_answers[current_set].end();si++)
		{
			cout<<*si<<endl;
		}
	}
	cout<<possible_answers[current_set].size()<<endl;
	
	return	0;
}
