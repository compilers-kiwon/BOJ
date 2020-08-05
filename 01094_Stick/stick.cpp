#include	<iostream>
#include	<queue>

using namespace std;

#define	FIRST_STICK_LEN	64

priority_queue<int>	stick_q;

int	main(void)
{
	int	X,total_stick_len;

	cin>>X;
	total_stick_len = FIRST_STICK_LEN;
	stick_q.push(-total_stick_len);
	
	for(;total_stick_len!=X;)
	{
		int	min_len_stick;
		
		min_len_stick = -stick_q.top();
		stick_q.pop();
		
		int	tmp_total_len;
		
		tmp_total_len = total_stick_len-min_len_stick+(min_len_stick/2);
		
		if( tmp_total_len >= X )
		{
			stick_q.push(-(min_len_stick/2));
			total_stick_len = tmp_total_len;
		}
		else
		{
			stick_q.push(-(min_len_stick/2));
			stick_q.push(-(min_len_stick/2));
		}	
	}
	cout<<stick_q.size()<<endl;
	
	return	0;	
}
