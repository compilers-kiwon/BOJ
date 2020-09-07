#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_MOVIES	(30+1)

int	M,P;
int	preference[MAX_NUM_OF_MOVIES];
int	total_preference,all_preference;

int		str2int(string& str)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+(int)(str[i]-'0');
	}
	
	return	ret;
}

void	get_preference(vector<int>& p,string& str)
{
	string	num;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			p.push_back(str2int(num));
			num.clear();
		}
		else
		{
			num.push_back(str[i]);
		}
	}
}

int		preference2int(vector<int>& p)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<p.size();i++)
	{
		ret |= 1<<p[i];
	}
	
	return	ret;
}

void	input(void)
{
	cin>>M>>P;
	getchar();
	
	for(int i=1;i<=M;i++)
	{
		string		str;
		vector<int>	p;
		
		getline(cin,str);
		get_preference(p,str);
		
		preference[i] = preference2int(p);
		all_preference |= preference[i];
	}
}

void	find_min_num_of_best_movies(int current_movie,int num_of_selected_movies,
									int current_preference,int& min_num_of_movies)
{
	if( current_movie>M || current_preference==total_preference )
	{
		if( current_preference == total_preference )
		{
			min_num_of_movies = min(min_num_of_movies,num_of_selected_movies);
		}
		return;
	}
	
	if( current_preference != (current_preference|preference[current_movie]) )
	{
		find_min_num_of_best_movies(current_movie+1,num_of_selected_movies+1,
									current_preference|preference[current_movie],
									min_num_of_movies);
	}
	
	find_min_num_of_best_movies(current_movie+1,num_of_selected_movies,
								current_preference,min_num_of_movies);
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	ret;
		
		all_preference = 0;
		input();
		
		total_preference = 0;
		
		for(int i=1;i<=P;i++)
		{
			total_preference |= 1<<i;
		}
		
		cout<<"Data Set "<<k<<":\n";
		
		if( all_preference != total_preference )
		{
			cout<<"Impossible\n\n";
			continue;
		}
		
		ret = MAX_NUM_OF_MOVIES;
		find_min_num_of_best_movies(1,0,0,ret);
		
		cout<<ret<<"\n\n";
	}
	
	return	0;
}
