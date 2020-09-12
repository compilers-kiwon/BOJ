#include	<iostream>
#include	<string>

using namespace	std;

#define	PUSH_BACK(str,c)	((str).push_back((c)))
#define	PUSH_FRONT(str,c)	((str).insert((str).begin(),(c)))

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		N;
		char	c;
		string	first_str;
		
		cin>>N;
		cin>>first_str;
		
		for(int i=2;i<=N;i++)
		{
			cin>>c;
			
			if( c <= first_str[0] )
			{
				PUSH_FRONT(first_str,c);
			}
			else
			{
				PUSH_BACK(first_str,c);
			 } 
		}
		cout<<first_str<<endl;
		
		T--;
	}
	
	return	0;
}
