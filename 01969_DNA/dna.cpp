#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE		(1000+1)
#define	NUM_OF_NUCLE	4
#define	get_index(c)	((c)=='A'?0:(c)=='C'?1:(c)=='G'?2:3)

const string	nucle = "ACGT";

int		N,M;
string	DNA[MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>DNA[i];
	}
}

int		find_most_appeared_nucle(int idx,int& num_of_appearance)
{
	int	cnt[NUM_OF_NUCLE],ret;
	
	fill(cnt,cnt+NUM_OF_NUCLE,0);
	
	for(int i=1;i<=N;i++)
	{
		char&	c = DNA[i][idx];
		
		cnt[get_index(c)]++;
	}
	
	num_of_appearance = 0;
	
	for(int i=0;i<NUM_OF_NUCLE;i++)
	{
		if( cnt[i] > num_of_appearance )
		{
			num_of_appearance = cnt[i];
			ret = i;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	string	str;
	int		sum;
	
	sum = 0;
	
	for(int i=0;i<M;i++)
	{
		int	n,diff;
		
		diff = find_most_appeared_nucle(i,n);
		
		str.push_back(nucle[diff]);
		sum += N-n;
	}
	
	cout<<str<<'\n'<<sum<<'\n';
	
	return	0;
}
