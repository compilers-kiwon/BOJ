#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_ROUND	(50+1)
#define	MAX_FRIENDS	(50+1)

#define	ROCK		'R'
#define	PAPER		'P'
#define	SCISSORS	'S'

#define	WIN		2
#define	TIE		1
#define	LOSS	0

int		get_score(char s,char f)
{
	int	score;
	
	if( s != f )
	{
		if( (s==ROCK&&f==SCISSORS) || (s==PAPER&&f==ROCK) || (s==SCISSORS&&f==PAPER) )
		{
			score = WIN;
		}
		else
		{
			score = LOSS;
		}
	}
	else
	{
		score = TIE;
	}
	
	return	score;
}

void	input(int num_of_rounds,int num_of_friends,
			  string& sang,vector<string>& friends)
{
	cin>>num_of_rounds>>sang>>num_of_friends;
	
	for(int i=1;i<=num_of_friends;i++)
	{
		string	f;
		
		cin>>f;
		friends.push_back(f);
	}
}

void	play(string& sang,vector<string>& friends,int& sang_score,int& max_score)
{
	for(int i=0;i<sang.length();i++)
	{
		int	num_of_rocks,num_of_papers,num_of_scissors;
		
		num_of_rocks = num_of_papers = num_of_scissors = 0;
		
		for(int j=0;j<friends.size();j++)
		{
			string&	f = friends[j];
			
			switch(f[i])
			{
				case	ROCK:
					num_of_rocks++;
					break;
				case	PAPER:
					num_of_papers++;
					break;
				case	SCISSORS:
					num_of_scissors++;
					break;
				default:
					// do nothing
					break;
			}
		}
		
		sang_score += get_score(sang[i],ROCK)*num_of_rocks;
		sang_score += get_score(sang[i],PAPER)*num_of_papers;
		sang_score += get_score(sang[i],SCISSORS)*num_of_scissors;
		
		int	rock_score,paper_score,scissors_score;
		
		rock_score = WIN*num_of_scissors+TIE*num_of_rocks;
		paper_score = WIN*num_of_rocks+TIE*num_of_papers;
		scissors_score = WIN*num_of_papers+TIE*num_of_scissors;
		
		max_score += max(rock_score,max(paper_score,scissors_score));
	}
}

int		main(void)
{
	int				R,N,sang_score,max_score;
	string			sang;
	vector<string>	friends;
	
	input(R,N,sang,friends);
	
	sang_score = max_score = 0;
	play(sang,friends,sang_score,max_score);
	
	cout<<sang_score<<'\n'<<max_score<<'\n';
	
	return	0;
}
