#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	A_CARD	0
#define	B_CARD	1
#define	C_CARD	2

typedef	pair<int,int>	Card;

vector<Card>	card;
int				A_ptr,B_ptr,C_ptr;

int		find_card(int from,int to,int tag)
{
	int	result;
	
	result = -1;
	
	for(int i=from;i<to;i++)
	{
		if( card[i].second == tag )
		{
			result = i;
			break;
		}
	}
	
	return	result;
}

void	init(int& A,int& B,int& C)
{
	cin.sync_with_stdio(false);
	
	cin>>A>>B>>C;
	
	for(int i=1;i<=A;i++)
	{
		int	n;
		
		cin>>n;
		card.push_back(make_pair(n,A_CARD));
	}
	
	for(int i=1;i<=B;i++)
	{
		int	n;
		
		cin>>n;
		card.push_back(make_pair(n,B_CARD));
	}
	
	for(int i=1;i<=C;i++)
	{
		int	n;
		
		cin>>n;
		card.push_back(make_pair(n,C_CARD));
	}
	
	sort(card.begin(),card.end());
	
	A_ptr = find_card(0,A+B+C,A_CARD);
	B_ptr = find_card(0,A+B+C,B_CARD);
	C_ptr = find_card(0,A+B+C,C_CARD);
}

int		main(void)
{
	int	A,B,C,answer;
	
	init(A,B,C);
	
	answer = 0x7FFFFFFF;
	
	for(bool flag=true;flag!=false;)
	{
		int	max_num_index,min_num_index;
		int	max_num,min_num;
		int	min_num_tag,next_min_num_index;
		//cout<<"["<<A_ptr<<"] "<<card[A_ptr].first<<" ["<<B_ptr<<"] "<<card[B_ptr].first<<" ["<<C_ptr<<"] "<<card[C_ptr].first<<'\n';
		max_num_index = max(A_ptr,max(B_ptr,C_ptr));
		min_num_index = min(A_ptr,min(B_ptr,C_ptr));
		
		max_num = card[max_num_index].first;
		min_num = card[min_num_index].first;
		
		answer = min(answer,abs(max_num-min_num));
		min_num_tag = card[min_num_index].second;
		
		next_min_num_index = find_card(min_num_index+1,A+B+C,min_num_tag);
		
		if( next_min_num_index == -1 )
		{
			flag = false;
		}
		else
		{
			switch(min_num_tag)
			{
				case	A_CARD:
					A_ptr = next_min_num_index;
					break;
				case	B_CARD:
					B_ptr = next_min_num_index;
					break;
				case	C_CARD:
					C_ptr = next_min_num_index;
					break;
			}
		}
	}
	
	cout<<answer<<'\n';
	
	return	0;
}
