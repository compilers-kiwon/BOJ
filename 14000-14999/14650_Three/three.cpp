#include	<iostream>
#include	<vector>

using namespace	std;

void	build_number(int current_digit_index,int max_digit,vector<int>& number,int& cnt)
{
	if( current_digit_index > max_digit )
	{
		int	sum,i;
		
		for(i=sum=0;i<number.size();i++)
		{
			sum += number[i];
		}
		
		if( sum%3 == 0 )
		{
			cnt++;
		}
		
		return;
	}
	
	number.push_back(0);
	build_number(current_digit_index+1,max_digit,number,cnt);
	number.pop_back();
	
	number.push_back(1);
	build_number(current_digit_index+1,max_digit,number,cnt);
	number.pop_back();
	
	number.push_back(2);
	build_number(current_digit_index+1,max_digit,number,cnt);
	number.pop_back();
}

int		main(void)
{
	int			N,cnt;
	vector<int>	number;
	
	cin>>N;
	cnt = 0;
	
	number.push_back(1);
	build_number(2,N,number,cnt);
	number.pop_back();
	
	number.push_back(2);
	build_number(2,N,number,cnt);
	number.pop_back();
	
	cout<<cnt<<endl;
	
	return	0;
}
