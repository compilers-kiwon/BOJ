#include	<iostream>
#include	<string>

using namespace	std;

#define	DICE_NUM	6

string	str[DICE_NUM+1] = {"","Yakk","Doh","Seh","Ghar","Bang","Sheesh"};

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int		d1,d2;
		string	output;
		
		cin>>d1>>d2;
		
		if( d1 == d2 )
		{
			switch(d1)
			{
				case 1:
					output = "Habb Yakk";
					break;
				case 2:
					output = "Dobara";
					break;
				case 3:
					output = "Dousa";
					break;
				case 4:
					output = "Dorgy";
					break;
				case 5:
					output = "Dabash";
					break;
				case 6:
					output = "Dosh";
					break;
			}
		}
		else
		{
			if( d1+d2 == 11 )
			{
				output = "Sheesh Beesh";
			}
			else
			{
				output = str[max(d1,d2)]+" "+str[min(d1,d2)];
			}
		}
		
		cout<<"Case "<<i<<": "<<output<<endl;
	}
	
	return	0;
}
