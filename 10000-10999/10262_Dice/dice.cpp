#include	<iostream>
#include	<vector>

using namespace	std;

void	build_dice(int from,int to,vector<int>& dice)
{
	for(int i=from;i<=to;i++)
	{
		dice.push_back(i);
	}
}

void	build_sum(vector<int>& d1,vector<int>& d2,vector<int>& s)
{
	for(int i=0;i<d1.size();i++)
	{
		for(int j=0;j<d2.size();j++)
		{
			s.push_back(d1[i]+d2[j]);
		}
	}
}

int		main(void)
{
	vector<int>	Gunnar_dice_1,Gunnar_dice_2,Gunnar_sum;
	vector<int>	Emma_dice_1,Emma_dice_2,Emma_sum;
	int			a1,b1,a2,b2;
	
	cin>>a1>>b1>>a2>>b2;
	
	build_dice(a1,b1,Gunnar_dice_1);
	build_dice(a2,b2,Gunnar_dice_2);
	
	cin>>a1>>b1>>a2>>b2;
	
	build_dice(a1,b1,Emma_dice_1);
	build_dice(a2,b2,Emma_dice_2);
	
	build_sum(Gunnar_dice_1,Gunnar_dice_2,Gunnar_sum);
	build_sum(Emma_dice_1,Emma_dice_2,Emma_sum);
	
	int	Gunnar_win_cnt,Emma_win_cnt;
	
	Gunnar_win_cnt = Emma_win_cnt = 0;
	
	for(int i=0;i<Gunnar_sum.size();i++)
	{
		for(int j=0;j<Emma_sum.size();j++)
		{
			if( Gunnar_sum[i] > Emma_sum[j] )
			{
				Gunnar_win_cnt++;
			}
			else if( Gunnar_sum[i] < Emma_sum[j] )
			{
				Emma_win_cnt++;
			}
		}
	}
	
	if( Gunnar_win_cnt > Emma_win_cnt )
	{
		cout<<"Gunnar\n";
	}
	else if( Gunnar_win_cnt < Emma_win_cnt )
	{
		cout<<"Emma\n";
	}
	else
	{
		cout<<"Tie\n";
	}
	
	return	0;
}
