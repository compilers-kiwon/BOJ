#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_WORDS	(100+1)

bool	is_palindrome(string& str)
{
	int		head,tail;
			
	for(head=0,tail=str.length()-1;head<tail;head++,tail--)
	{
		if( str[head] != str[tail] )
		{
			break;
		}
	}
	
	if( head < tail )
	{
		return	false;
	}
	
	cout<<str<<'\n';
	
	return	true;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		k;
		string	w[MAX_NUM_OF_WORDS];
		bool	found;
		
		cin>>k;
		
		for(int i=1;i<=k;i++)
		{
			cin>>w[i];
		}
		
		found = false;
		
		for(int i=1;i<=k-1;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				string	tmp;
				
				tmp = w[i]+w[j];
				
				if( is_palindrome(tmp) == true )
				{
					found = true;
					break;
				}
				else
				{
					tmp = w[j]+w[i];
					
					if( is_palindrome(tmp) == true )
					{
						found = true;
						break;
					}
				}
			}
			
			if( found == true )
			{
				break;
			}
		}
		
		if( found == false )
		{
			cout<<"0\n";
		}
		
		T--;
	}
	
	return	0;
}
