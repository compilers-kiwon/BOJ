#include	<iostream>
#include	<string>

using namespace std;

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		score,i,prev_score;
		string	str;
		
		cin>>str;
		
		for(prev_score=0,score=0,i=0;i<str.length();i++)
		{
			if( str[i] == 'X' )
			{
				prev_score = 0;
			}
			else
			{
				score = score+(++prev_score);
			}
		}
		cout<<score<<endl;
		
		T--;
	}
	
	return	0;
}
