#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	wait;
	int		X,cnt,W,M;
	
	cin>>X>>wait;
	W = M = cnt = 0;
	
	for(int i=0;i<wait.length();i++)
	{
		int	W_tmp,M_tmp;
		
		if( wait[i] == 'W' )
		{
			W_tmp = W+1;
			M_tmp = M;
		}
		else
		{
			W_tmp = W;
			M_tmp = M+1;
		}
		
		if( max(W_tmp,M_tmp)-min(W_tmp,M_tmp) <= X )
		{
			W =	W_tmp;
			M = M_tmp;
			cnt++;
		}
		else
		{
			if( i<wait.length()-1 && wait[i]!=wait[i+1] )
			{
				
				swap(wait[i],wait[i+1]);
				
				if( wait[i] == 'W' )
				{
					W_tmp = W+1;
					M_tmp = M;
				}
				else
				{
					W_tmp = W;
					M_tmp = M+1;
				}
				
				if( max(W_tmp,M_tmp)-min(W_tmp,M_tmp) <= X )
				{
					W =	W_tmp;
					M = M_tmp;
					cnt++;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
