#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_H	7
#define	MAX_W	5

#define	MAX_LEN	(30*MAX_W)

const string number[10][MAX_H] = {
	{"xxxxx","x...x","x...x","x...x","x...x","x...x","xxxxx"},
	{"....x","....x","....x","....x","....x","....x","....x"},
	{"xxxxx","....x","....x","xxxxx","x....","x....","xxxxx"},
	{"xxxxx","....x","....x","xxxxx","....x","....x","xxxxx"},
	{"x...x","x...x","x...x","xxxxx","....x","....x","....x"},
	{"xxxxx","x....","x....","xxxxx","....x","....x","xxxxx"},
	{"xxxxx","x....","x....","xxxxx","x...x","x...x","xxxxx"},
	{"xxxxx","....x","....x","....x","....x","....x","....x"},
	{"xxxxx","x...x","x...x","xxxxx","x...x","x...x","xxxxx"},
	{"xxxxx","x...x","x...x","xxxxx","....x","....x","xxxxx"}
};

const string plus[MAX_H] = {".....","..x..","..x..","xxxxx","..x..","..x..","....."};

string	in_buf[MAX_H],out_buf[MAX_H];

bool	compare(int s_col,int n)
{
	bool	result;
	
	result = true;
	
	for(int row=0;row<MAX_H&&result==true;row++)
	{
		for(int col=0;col<MAX_W&&result==true;col++)
		{
			if( in_buf[row][s_col+col] != number[n][row][col] )
			{
				result = false;
			}
		}
	}
	
	return	result;
}

int		main(void)
{
	for(int row=0;row<MAX_H;row++)
	{
		cin>>in_buf[row];
	}
	
	int		a,b,sum;
	int*	t;
	
	a = b = 0;
	t = &a;
	
	for(int col=0;col<in_buf[0].length();col+=MAX_W+1)
	{
		bool	found;
		
		found = false;
		
		for(int i=0;i<=9&&found!=true;i++)
		{
			if( compare(col,i) == true )
			{
				*t = *t*10+i;
				found = true;
			}
		}
		
		if( found == false )
		{
			t = &b;
		}
	}
	
	vector<int>	digit;
	
	for(sum=a+b;sum>0;sum/=10)
	{
		digit.push_back(sum%10);
	}
	
	for(int row=0;row<MAX_H;row++)
	{
		for(int i=digit.size()-1;i>=0;i--)
		{
			out_buf[row] += number[digit[i]][row];
			
			if( i != 0 )
			{
				out_buf[row].push_back('.');
			}
		}
	}
	
	for(int row=0;row<MAX_H;row++)
	{
		cout<<out_buf[row]<<'\n';
	}
	
	return	0;
}
