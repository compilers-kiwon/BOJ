#include	<iostream>

using namespace	std;

#define	MAX_SIZE			(100+1)
#define	NONE				0
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		N,K,a[MAX_SIZE];
bool	available[MAX_SIZE];

void	input(void)
{
	cin>>N>>K;
	
	for(int	i=1;i<=N;i++)
	{
		cin>>a[i];
		available[i] = true;
	}
}

int		get_card(int from)
{
	int	ret;
	
	ret = NONE;
	
	for(int i=from;i>=1;i--)
	{
		if( available[i] == true )
		{
			ret = i;
			break;
		}
	}
	
	return	ret;
}

int		count_left_cards(void)
{
	int	ret;
	
	ret = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( available[i] == true )
		{
			ret++;
			cout<<a[i]<<' ';
		}
	}
	cout<<'\n';
	return	ret;
}

void	simulate(void)
{
	bool	updated;
	
	updated = false;
	
	for(int right=1;right<=N;right++)
	{
		int left,mid;
		
		if( (mid=get_card(right-1))!=NONE && (left=get_card(mid-1))!=NONE )
		{
			if( a[mid]-a[left]==K && a[right]-a[mid]==K )
			{
				updated = true;
				available[left] = available[mid] = available[right] = false;
				cout<<a[left]<<' '<<a[mid]<<' '<<a[right]<<" are removed!!\n";
				count_left_cards();
			}
		}
	}
	
	if( updated == true )
	{
		simulate();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		input();
		simulate();
		
		cout<<"Case #"<<t<<": "<<count_left_cards()<<'\n';
	}
	
	return	0;
}
