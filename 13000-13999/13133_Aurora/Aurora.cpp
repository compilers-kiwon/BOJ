#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	(500+1)

typedef	struct	_PERSON_INFO	Person;
struct	_PERSON_INFO
{
	bool	is_available;
	int		mother,father;
};

int	main(void)
{
	int		N,M;
	Person	p[MAX_NUM_OF_PEOPLE];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>p[i].mother>>p[i].father;
		p[i].is_available = true;
	}
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	m;
		
		cin>>m;
		p[m].is_available = false;
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( p[i].is_available == true )
		{
			if( p[i].mother != 0 && p[i].father != 0 )
			{
				if( p[p[i].mother].is_available == true && p[p[i].father].is_available == true )
				{
					cnt++;
				}
			}
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
