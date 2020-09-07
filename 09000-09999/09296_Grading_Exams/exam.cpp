#include	<iostream>
#include	<string>

using namespace	std;

int	count_wrong_answer(string& answer_key,string& student_answer,int len)
{
	int	cnt,i;
	
	for(i=cnt=0;i<len;i++)
	{
		if( answer_key[i] != student_answer[i] )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int		L;
		string	a,b;
		
		cin>>L>>a>>b;
		cout<<"Case "<<i<<": "<<count_wrong_answer(a,b,L)<<'\n';
	}
	
	return	0;
}
