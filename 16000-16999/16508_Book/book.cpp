#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SIZE			0x100
#define	MAX_NUM_OF_BOOKS	(16+1)

typedef	struct	_BOOK_INFO	Book;
struct	_BOOK_INFO
{
	int				price;
	map<char,int>	cnt;
};

string			T;
int				N,min_price;
map<char,int>	T_cnt;
Book			book[MAX_NUM_OF_BOOKS];

bool	is_table_empty(void)
{
	map<char,int>::iterator	it;
	bool					flag;
	
	for(it=T_cnt.begin(),flag=true;it!=T_cnt.end();it++)
	{
		if( it->second > 0 )
		{
			flag = false;
			break;
		}
	}
	
	return	flag;
}

void	build_str(int book_index,int current_cost)
{
	if( book_index > N )
	{
		return;
	}
	
	map<char,int>&			current = book[book_index].cnt;
	map<char,int>::iterator	it;
	
	for(it=current.begin();it!=current.end();it++)
	{
		T_cnt[it->first] -= it->second;
	}
	
	if( is_table_empty() == true )
	{
		min_price = min(min_price,current_cost+book[book_index].price);
	}
	else
	{
		build_str(book_index+1,current_cost+book[book_index].price);
	}
	
	for(it=current.begin();it!=current.end();it++)
	{
		T_cnt[it->first] += it->second;
	}
	
	build_str(book_index+1,current_cost);
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>T>>N;
	
	for(int i=0;i<T.length();i++)
	{
		T_cnt[T[i]]++;
	}
	
	for(int i=1;i<=N;i++)
	{
		string	name;
		
		cin>>book[i].price>>name;
		
		for(int j=0;j<name.length();j++)
		{
			book[i].cnt[name[j]]++;
		}
	}
}

int		main(void)
{
	init();
	
	min_price = 0x7FFFFFFF;
	
	build_str(1,0);
	
	if( min_price == 0x7FFFFFFF )
	{
		min_price = -1;
	}
	
	cout<<min_price<<'\n';
	
	return	0;
}
