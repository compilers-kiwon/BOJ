#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

int	get_min_num_of_operation(string& init,string& final)
{
	int	white_cnt,black_cnt,i;
	
	for(i=white_cnt=black_cnt=0;i<init.length();i++)
	{
		if( init[i] != final[i] )
		{
			if( init[i] == 'W' )
			{
				white_cnt++;
			}
			else
			{
				black_cnt++;
			}
		}
	}
	
	return	abs(white_cnt-black_cnt)+min(white_cnt,black_cnt);
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		N;
		string	init,final;
		
		cin>>N>>init>>final;
		cout<<get_min_num_of_operation(init,final)<<endl;
		
		T--;
	}
	
	return	0;
}
