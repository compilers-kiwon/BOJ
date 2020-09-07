#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_SUSPECTS		(50+1)
#define	MAX_NUM_OF_WITNESSES	(200+1)

#define	in_range(MIN,n,MAX)		((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_TESTIMONY_INFO	Testimony;
struct	_TESTIMONY_INFO
{
	int	suspect_idx,place,begin_time,end_time;
};

void	input(int& num_of_suspects,
			  int& num_of_witnesses,
			  int& time_of_crime,
			  Testimony* testimonies)
{
	int	p;
	
	cin>>num_of_suspects>>num_of_witnesses>>p>>time_of_crime;
	
	for(int i=1;i<=num_of_witnesses;i++)
	{
		Testimony&	t = testimonies[i];
		
		cin>>t.suspect_idx>>t.place>>t.begin_time>>t.end_time;
	}
}

bool	is_time_overlapped(Testimony& t1,Testimony& t2)
{
	if( t1.begin_time == t2.begin_time )
	{
		return	true;
	}
	
	int	first_begin,first_end,second_begin,second_end;
	
	if( t1.begin_time < t2.begin_time )
	{
		first_begin = t1.begin_time;
		first_end = t1.end_time;
		
		second_begin = t2.begin_time;
		second_end = t2.end_time;
	}
	else
	{
		first_begin = t2.begin_time;
		first_end = t2.end_time;
		
		second_begin = t1.begin_time;
		second_end = t1.end_time;
	}
	
	return	in_range(first_begin,second_begin,first_end);
}

bool	is_consistent(Testimony& t1,Testimony& t2)
{
	if( t1.suspect_idx!=t2.suspect_idx || t1.place==t2.place )
	{
		return	true;
	}
	
	if( is_time_overlapped(t1,t2) == true )
	{
		return	false;
	}
	
	return	true;
}

void	check_trust(int& num_of_witnesses,
					Testimony* testimonies,
					bool* trust)
{
	for(int i=1;i<=num_of_witnesses;i++)
	{
		for(int j=i+1;j<=num_of_witnesses;j++)
		{
			if( is_consistent(testimonies[i],testimonies[j]) == false )
			{
				trust[i] = trust[j] = false;
			}
		}
	}
}

void	get_suspects_under_suspicion(int& num_of_witnesses,
									 Testimony* testimonies,
									 int time_of_crime,
									 bool* trust,
									 bool* suspicion)
{
	for(int i=1;i<=num_of_witnesses;i++)
	{
		Testimony&	t = testimonies[i];
		
		if( trust[i]==true && in_range(t.begin_time,time_of_crime,t.end_time) )
		{
			suspicion[t.suspect_idx] = false;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int			num_of_suspects;
		int			num_of_witnesses;
		int			time_of_crime;
		Testimony	testimonies[MAX_NUM_OF_WITNESSES];
		bool		trust[MAX_NUM_OF_WITNESSES];
		bool		suspicion[MAX_NUM_OF_SUSPECTS];
		bool		suspicion_flag;
		
		input(num_of_suspects,num_of_witnesses,time_of_crime,testimonies);
		
		fill(&trust[1],&trust[num_of_witnesses+1],true);
		check_trust(num_of_witnesses,testimonies,trust);
		
		fill(&suspicion[1],&suspicion[num_of_suspects+1],true);
		get_suspects_under_suspicion(num_of_witnesses,testimonies,time_of_crime,trust,suspicion);
		
		suspicion_flag = false;
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=1;i<=num_of_suspects;i++)
		{
			if( suspicion[i] == true )
			{
				cout<<i<<'\n';
				suspicion_flag = true;
			}
		}
		
		if( suspicion_flag == false )
		{
			cout<<"No suspect.\n";
		}
		cout<<'\n';
	}
	
	return	0;
}
