#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	5

typedef	pair<char,int>	Card;

Card	c[MAX_SIZE];
int		max_num;

void	input(void)
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		cin>>c[i].first>>c[i].second;
		max_num = max(max_num,c[i].second);
	}
}

bool	is_same_color(int s,int size)
{
	char	color;
	
	color = c[s].first;
	
	for(int i=1;i<size;i++)
	{
		if( color != c[s+i].first )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	is_number_consecutive(int s,int size,const vector<int>& order)
{
	for(int i=1;i<size;i++)
	{
		if( (c[order[s+i]].second-c[order[s]].second) != i )
		{
			return	false;
		}
	}
	return	true;
}

bool	is_same_number(int s,int size,const vector<int>& order)
{
	int	num;
	
	num = c[order[s]].second;
	
	for(int i=1;i<size;i++)
	{
		if( num != c[order[s+i]].second )
		{
			return	false;
		}
	}
	
	return	true;
}

int		get_max_score(void)
{
	int		ret;
	bool	same_color;
	
	ret = 0;
	same_color = is_same_color(0,MAX_SIZE);
	
	// 4
	if( same_color == true )
	{
		ret = max(ret,max_num+600);
	}
	
	vector<int>	card_order;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		card_order.push_back(i);
	}
	
	do{
		// 1
		if( same_color && is_number_consecutive(0,MAX_SIZE,card_order) )
		{
			ret = max(ret,max_num+900);
		}
		
		// 2
		if( is_same_number(0,4,card_order) == true )
		{
			ret = max(ret,c[card_order[0]].second+800);
		}
		
		// 3
		if( is_same_number(0,3,card_order) && is_same_number(3,2,card_order) )
		{
			ret = max(ret,c[card_order[0]].second*10+c[card_order[3]].second+700);
		}
		
		// 5
		if( is_number_consecutive(0,MAX_SIZE,card_order) == true )
		{
			ret = max(ret,max_num+500);
		}
	
		// 6
		if( is_same_number(0,3,card_order) == true )
		{
			ret = max(ret,c[card_order[0]].second+400);
		}
		
		// 7
		if( is_same_number(0,2,card_order) && is_same_number(2,2,card_order) )
		{
			int	tmp;
			
			tmp = max(c[card_order[0]].second,c[card_order[2]].second)*10
					+min(c[card_order[0]].second,c[card_order[2]].second);
			ret = max(ret,tmp+300);
		}
		
		// 8
		if( is_same_number(0,2,card_order) == true )
		{
			ret = max(ret,c[card_order[0]].second+200);
		}
	}while(next_permutation(card_order.begin(),card_order.end()));
	
	// 9
	if( ret == 0 )
	{
		ret = max_num+100;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_max_score()<<'\n';
	
	return	0;
}
