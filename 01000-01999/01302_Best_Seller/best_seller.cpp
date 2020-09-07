#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<string,int>	book;

void	input(int& num_of_books)
{
	cin>>num_of_books;
	
	for(int i=1;i<=num_of_books;i++)
	{
		string	book_name;
		
		cin>>book_name;
		book[book_name]++;
	}
}

void	find_best_seller(string& name)
{
	map<string,int>::iterator	mi;
	
	int	result = 0;
	
	for(mi=book.begin();mi!=book.end();mi++)
	{
		if( mi->second > result )
		{
			result = mi->second;
			name = mi->first;
		}	
	}	
}

int		main(void)
{
	int		N;
	string	best_seller;
	
	input(N);
	find_best_seller(best_seller);
	cout<<best_seller<<endl;
	
	return	0;
}
