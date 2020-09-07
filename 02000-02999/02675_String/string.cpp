#include	<iostream>
#include	<string>

using namespace std;

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T-->0)
	{
		int		R;
		string	S;
		
		cin>>R>>S;
		
		for(int	i=0;i<S.length();i++)
		{
			for(int j=1;j<=R;j++)
			{
				cout<<S[i];
			}
		}
		cout<<endl;
	}
	
	return	0;
}
