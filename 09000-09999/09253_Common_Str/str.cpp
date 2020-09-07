#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN		(200000+1)
#define	MAX_SIZE	26

#define	get_index(c)	((int)((c)-'a'))

int	A_table[MAX_LEN][MAX_SIZE],B_table[MAX_LEN][MAX_SIZE];
int	C_table[MAX_SIZE];

void	build_table(string& str,int t[][MAX_SIZE])
{
	for(int i=1;i<str.length();i++)
	{
		for(int j=0;j<MAX_SIZE;j++)
		{
			t[i][j] = t[i-1][j];
		}
		t[i][get_index(str[i])]++;
	}
}

bool	compare_table(int* src_end,int* src_begin,int* sub)
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		if( src_end[i]-src_begin[i] != sub[i] )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	find_sub_str(string& src,string& sub,int src_from)
{
	for(int i=0;i<sub.length();i++)
	{
		if( src[src_from+i] != sub[i] )
		{
			return	false;
		}
	}

	return	true;
}

bool	is_sub_str(string& src,string& sub,int src_table[][MAX_SIZE],int* sub_table)
{
	for(int from=1,to=sub.length();to<src.length();from++,to++)
	{
		if( compare_table(&src_table[to][0],&src_table[from-1][0],sub_table) == false )
		{
			continue;
		}
	
		if( find_sub_str(src,sub,from) == true )
		{
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	A,B,C;
	
	cin>>A>>B>>C;
	
	A.insert(A.begin(),' ');
	B.insert(B.begin(),' ');
	
	build_table(A,A_table);
	build_table(B,B_table);
	
	for(int i=0;i<C.length();i++)
	{
		C_table[get_index(C[i])]++;
	}
	
	if( is_sub_str(A,C,A_table,C_table) && is_sub_str(B,C,B_table,C_table) )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}
