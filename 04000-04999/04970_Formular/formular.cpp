#include	<iostream>
#include	<string>

using namespace	std;

#define	NONE		-1
#define	MAX_SIZE	3
#define	OUTPUT		2

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const int	not_table[MAX_SIZE] = {2,1,0};
const int	and_table[MAX_SIZE][MAX_SIZE] = {{0,0,0},{0,1,1},{0,1,2}};
const int	or_table[MAX_SIZE][MAX_SIZE] = {{0,1,2},{1,1,2},{2,2,2}};

int	value[MAX_SIZE*MAX_SIZE*MAX_SIZE][MAX_SIZE];

int	is_formular(string& exp,int ptr,int& result,int v)
{
	char&	c = exp[ptr];
	
	if( IN_RANGE('0',c,'2') == true )
	{
		result = (int)(c-'0');
		return	ptr+1;
	}
	
	if( IN_RANGE('P',c,'R') == true )
	{
		result = value[v][(int)(c-'P')];
		return	ptr+1;
	}
	
	int	f1,f2,ptr1,ptr2;
	
	if( c == '-' )
	{
		ptr1 = is_formular(exp,ptr+1,f1,v);
		
		if( ptr1 != NONE )
		{
			result = not_table[f1];
			
			return	ptr1;
		}
	}
	
	if( c == '(' )
	{
		ptr1 = is_formular(exp,ptr+1,f1,v);
		
		if( ptr1!=NONE && (exp[ptr1]=='*'||exp[ptr1]=='+') )
		{
			ptr2 = is_formular(exp,ptr1+1,f2,v);
			
			if( ptr2!=NONE && exp[ptr2]==')' )
			{
				if( exp[ptr1] == '*' )
				{
					result = and_table[f1][f2];
				}
				else
				{
					result = or_table[f1][f2];
				}
				
				return	ptr2+1;
			}
		}
	}
	
	return	NONE;
}

int	get_num_of_output(string& exp)
{
	int	value[MAX_SIZE] = {0,1,2};
	int	ret;
	
	ret = 0;
	
	for(int v=0;v<MAX_SIZE*MAX_SIZE*MAX_SIZE;v++)
	{
		int	result;
		
		is_formular(exp,0,result,v);
		
		if( result == OUTPUT )
		{
			ret++;
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	cnt;
	
	cnt = 0;
	
	for(int p=0;p<MAX_SIZE;p++)
	{
		for(int q=0;q<MAX_SIZE;q++)
		{
			for(int r=0;r<MAX_SIZE;r++)
			{
				value[cnt][0] = p;
				value[cnt][1] = q;
				value[cnt][2] = r;
				cnt++;
			}
		}
	}
	
	for(;;)
	{
		string	exp;
		int		result;
		
		cin>>exp;
		
		if( exp == "." )
		{
			break;
		}
		
		cout<<get_num_of_output(exp)<<'\n';
	}
	
	return	0;
}
