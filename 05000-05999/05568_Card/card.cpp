#include	<iostream>
#include	<string>
#include	<set>

using namespace	std;

#define	MAX_NUM_OF_CARD	(10+1)

string		card[MAX_NUM_OF_CARD];
int			n,k;
set<string>	number_set;

void	select_card(int num_of_selected_card,string number)
{
	if( num_of_selected_card == k )
	{
		number_set.insert(number);
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if( card[i] != "" )
		{
			string	tmp;
			
			tmp = card[i];
			card[i] = "";
			
			select_card(num_of_selected_card+1,number+tmp);
			
			card[i] = tmp;
		}
	}
}

int		main(void)
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	
	select_card(0,"");
	cout<<number_set.size()<<endl;
	
	return	0;
}
