#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN	(80+1)

bool	compare(char* seq,int index1,int index2,int len)
{
	bool	result;
	int		i,cnt;
	
	for(i=0,result=true;i<len;i++)
	{
		if( seq[index1+i] != seq[index2+i] )
		{
			result = false;
			break;
		}
	}
	return	result;
}

bool	find_duplication(char* seq,int index)
{
	int		s1,s2,compare_len;
	bool	result;
	
	s1=index-3,s2=index-1,compare_len=2;
	for(result=false;s1>=0;s1-=2,s2-=1,compare_len++)
	{
		if( compare(seq,s1,s2,compare_len) == true )
		{
			result = true;
			break;
		}
	}
	return	result;
}

bool	build_seq(char* seq,int index,int max_len)
{
	if( index == max_len )
	{
		return	true;
	}
		
	for(char c='1';c<='3';c++)
	{
		if( c == seq[index-1] )
		{
			continue;
		}
		
		seq[index] = c;
		
		if( find_duplication(seq,index) == false && build_seq(seq,index+1,max_len) == true )
		{
			return	true;
		}
	}
	return	false;
}

int		main(void)
{
	char	seq[MAX_LEN];
	int		N;
	
	scanf("%d",&N);
	
	for(char c='1';c<='3';c++)
	{
		seq[0] = c;seq[1] = '\0';
		
		if( build_seq(seq,1,N) == true )
		{
			break;
		}
	}
	seq[N] = '\0';
	
	puts(seq);
	
	return	0;
}
