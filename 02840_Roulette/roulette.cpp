#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	int		N,K,current_pos,i;
	bool	flag;
	
	map<char,int>	counter;
	
	cin>>N>>K;
	
	string	roulette(N,'?');
	
	for(i=1,current_pos=0,flag=true;i<=K && flag==true;i++)
	{
		int		S;
		char	c;
		
		cin>>S>>c;
		
		current_pos = (current_pos+S)%N;
		
		if( roulette[current_pos] == c )
		{
			continue;
		}
		
		if( roulette[current_pos] == '?' )
		{
			if( counter[c] == 0 )
			{
				roulette[current_pos] = c;
				counter[c] = 1;
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}
	
	if( flag == false )
	{
		cout<<"!\n";
		return	0;
	}
	
	for(i=current_pos;i>=0;i--)
	{
		cout<<roulette[i];
	}
	
	for(i=N-1;i>current_pos;i--)
	{
		cout<<roulette[i];
	}
	
	cout<<endl;
	
	return	0;
}
