#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<string>

using namespace	std;

#define	MAX_NUM			13
#define	NUM_OF_CARDS	5
#define	char2int(c)		((int)((c)-'0'))

#define	TRUE	3
#define	FALSE	0

typedef	pair<int,char>	Card;

void	input(Card* cards)
{
	for(int i=1;i<=NUM_OF_CARDS;i++)
	{
		string	s;
		int		n;
		
		cin>>s;
		
		switch(s[0])
		{
			case 'A':
				n = 1;
				break;
			case 'J':
				n = 11;
				break;
			case 'Q':
				n = 12;
				break;
			case 'K':
				n = 13;
				break;
			default:
				if( s[1] == '0' )
				{
					n = 10;
				}
				else
				{
					n = char2int(s[0]);
				}
				break;
		}
		
		cards[i] = make_pair(n-1,s[s.length()-1]);
	}
}

bool	compare_card(Card& c1,Card& c2)
{
	bool	ret;
	
	if( c1.first == c2.first )
	{
		if( c1.second < c2.second )
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
	}
	else
	{
		if( c1.first < c2.first )
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
	}
	
	return	ret;
}

Card	assistant(vector<Card>& cards)
{
	Card&	c0 = cards[0];
	Card&	c1 = cards[1];
	Card&	c2 = cards[2];
	Card&	c3 = cards[3];
	int		smallest,not_in_order;
	Card	ret;
	
	if( compare_card(c1,c2) == true )
	{
		smallest = 1;
	}
	else
	{
		smallest = 2;
	}
	
	if( compare_card(cards[smallest],c3) == false )
	{
		smallest = 3;
	}
	
	not_in_order = FALSE;
	
	switch(smallest)
	{
		case 1:
			if( compare_card(c2,c3) == false )
			{
				not_in_order = TRUE;
			}
			break;
		case 2:
			if( compare_card(c1,c3) == false )
			{
				not_in_order = TRUE;
			}
			break;
		case 3:
			if( compare_card(c1,c2) == false )
			{
				not_in_order = TRUE;
			}
			break;
		default:
			// do nothing
			break;
	}
	
	ret.first = (c0.first+smallest+not_in_order)%MAX_NUM;
	ret.second = c0.second;
	
	return	ret;
}

void	print_card(int p,vector<Card>& c)
{
	cout<<"Problem "<<p<<": ";
	
	for(int i=0;i<c.size();i++)
	{
		++c[i].first;
		
		switch(c[i].first)
		{
			case 1:
				cout<<'A';
				break;
			case 11:
				cout<<'J';
				break;
			case 12:
				cout<<'Q';
				break;
			case 13:
				cout<<'K';
				break;
			default:
				cout<<c[i].first;
				break;
		}
		
		cout<<c[i].second<<' ';
	}
	cout<<'\n';
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		Card	c[NUM_OF_CARDS+1];
		
		input(c);
		
		for(int j=1;j<=NUM_OF_CARDS;j++)
		{
			vector<int>	order;
			
			Card&	audience = c[j];
			bool	found;
			
			for(int k=1;k<=NUM_OF_CARDS;k++)
			{
				if( k == j )
				{
					continue;
				}
				
				order.push_back(k);
			}
			
			found = false;
			
			do{
				vector<Card>	v;
				
				for(int m=0;m<order.size();m++)
				{
					v.push_back(c[order[m]]);
				}
				
				if( assistant(v) == audience )
				{
					found = true;
					break;
				}
			}while(next_permutation(order.begin(),order.end()));
			
			if( found == true )
			{
				vector<Card>	v;
				
				v.push_back(audience);
				
				for(int m=0;m<order.size();m++)
				{
					v.push_back(c[order[m]]);
				}
				
				print_card(i,v);
				
				break;
			}
		}
	}
	
	return	0;
}
