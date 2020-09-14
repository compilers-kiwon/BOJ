#include	<iostream>
#include	<vector>

using namespace	std;

#define	NUM_OF_DAYS			31
#define	MAX_NUM_OF_RECORD	(100+1)

typedef	struct	_RECORD_INFO	Record;
struct	_RECORD_INFO
{
	vector<int>	borrow,give_back;
};


void	init(int& num_of_records,Record* rec,int& num_of_books)
{
	cin>>num_of_records;
	
	for(int i=1;i<=num_of_records;i++)
	{
		int	d1,d2;
		
		cin>>d1>>d2;
		
		rec[d1].borrow.push_back(i);
		rec[d2].give_back.push_back(i);
	}
	
	cin>>num_of_books;
}

int		simulate(int num_of_books,Record* rec)
{
	int				cnt,day;
	vector<bool>	is_done(MAX_NUM_OF_RECORD,false);
	
	for(cnt=0,day=1;day<=NUM_OF_DAYS;day++)
	{
		vector<int>&	first = rec[day].borrow;
		vector<int>&	second = rec[day].give_back;
		
		for(int i=0;i<second.size();i++)
		{
			if( is_done[second[i]] == true )
			{
				num_of_books++;
			}
		}
		
		for(int i=0;i<first.size();i++)
		{
			if( num_of_books > 0 )
			{
				num_of_books--;
				cnt++;
				is_done[first[i]] = true;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	int		N,K;
	Record	r[NUM_OF_DAYS+1];
	
	init(N,r,K);
	
	if( simulate(K,r) == N )
	{
		puts("1");
	}
	else
	{
		puts("0");
	}
	
	return	0;
}
