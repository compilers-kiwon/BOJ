#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	GOOD			100

#define	SOONGSIL		0
#define	KOREA			1
#define	HANYANG			2
#define	MAX_UNIVERSITY	3

const string	name[MAX_UNIVERSITY] = {"Soongsil","Korea","Hanyang"};

typedef	pair<int,int>	Contribution;

int	input(priority_queue<Contribution>& pq)
{
	int	ret;
	
	ret = 0;
	
	for(int i=SOONGSIL;i<=HANYANG;i++)
	{
		int	n;
		
		cin>>n;
		
		pq.push(make_pair(-n,i));
		ret += n;
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<Contribution>	pq;
	
	if( input(pq) >= GOOD )
	{
		cout<<"OK\n";
	}
	else
	{
		cout<<name[pq.top().second]<<'\n';
	}
	
	return	0;
}
