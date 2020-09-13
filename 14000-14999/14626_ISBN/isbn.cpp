#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_DIGIT	13
#define	char2int(c)		((int)((c)-'0'))

bool	check_isbn(string& isbn,int* num,int digit,int& answer)
{
	if( digit == NUM_OF_DIGIT )
	{
		int	n,i;
		
		for(i=n=0;i<NUM_OF_DIGIT;i++)
		{
			n += (1+(i%2)*2)*num[i];
		}
		
		return	((n%10)==0);
	}
	
	if( isbn[digit] != '*' )
	{
		num[digit] = char2int(isbn[digit]);
		return	check_isbn(isbn,num,digit+1,answer);
	}
	
	for(int i=0;i<=9;i++)
	{
		num[digit] = i;
		
		if( check_isbn(isbn,num,digit+1,answer) == true )
		{
			answer = i;
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	int		n[NUM_OF_DIGIT],answer;
	string	isbn;
	
	cin>>isbn;
	check_isbn(isbn,n,0,answer);
	cout<<answer<<endl;
	
	return	0;
	
}
