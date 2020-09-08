#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

int		find_min_num_of_toggle(string& lock,int lock_len)
{
	int		cnt,i,j;
	string	unlock(lock_len,'0');
	
	for(i=cnt=0,j=lock_len-1;i<lock_len-1;i++,j--)
	{
		if( lock[i] == unlock[i] )
		{
			continue;
		}
		
		cnt += pow(2,j);
		unlock[i+1] = '1';
	}
	
	if( lock[lock_len-1] != unlock[lock_len-1] )
	{
		cnt++;
	}
	
	return	cnt;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	B;
		
		cin>>B;
		cout<<find_min_num_of_toggle(B,B.length())<<endl;
		
		T--;
	}
	return	0;
}
