#include	<iostream>
#include	<map>

using namespace	std;

#define	DICE_NUM		6
#define	MAX_PRIZE		(50000+DICE_NUM*5000)
#define	NUM_OF_NUMBERS	4

#define	ALL_FOUR_SAME	1
#define	THREE_SAME		2
#define	TWO_TWO_SAME	3
#define	JUST_TWO_SAME	4
#define	ALL_DIFFERENT	5

int	find_result(int* d,int& n1,int& n2)
{
	int	count_of_dice_number[DICE_NUM+1] = {0,0,0,0,0,0,0};
	int	result;
	
	count_of_dice_number[d[1]]++;
	count_of_dice_number[d[2]]++;
	count_of_dice_number[d[3]]++;
	count_of_dice_number[d[4]]++;
	
	int	count_of_same_number,cnt;
	
	count_of_same_number = 0;
	
	for(int i=1;i<=DICE_NUM;i++)
	{
		if( count_of_dice_number[i] > count_of_same_number )
		{
			count_of_same_number = count_of_dice_number[i];
			cnt = 1;
			n1 = i;
		}
		else if( count_of_dice_number[i] == count_of_same_number )
		{
			cnt++;
			n2 = i;
		}
	}
	
	switch(count_of_same_number)
	{
		case	4:
			result = ALL_FOUR_SAME;
			break;
		case	3:
			result = THREE_SAME;
			break;
		case	2:
			if( cnt == 1 )
			{
				result = JUST_TWO_SAME;
			}
			else
			{
				result = TWO_TWO_SAME;
			}
			break;
		default:
			result = ALL_DIFFERENT;
			n1 = n2;
			break;
	}
	
	return	result;	
}

int		main(void)
{
	int	N,max_prize,i;
	
	cin>>N;
	
	for(i=1,max_prize=0;i<=N;i++)
	{
		int	dice_n[NUM_OF_NUMBERS+1];
		int	result,n1,n2,current_prize;
		
		cin>>dice_n[1]>>dice_n[2]>>dice_n[3]>>dice_n[4];
		
		result = find_result(dice_n,n1,n2);
		
		switch(result)
		{
			case	ALL_FOUR_SAME:
				current_prize = 50000+n1*5000;
				break;
			case	THREE_SAME:
				current_prize = 10000+n1*1000;
				break;
			case	TWO_TWO_SAME:
				current_prize = 2000+n1*500+n2*500;
				break;
			case	JUST_TWO_SAME:
				current_prize = 1000+n1*100;
				break;
			default :
				current_prize = n1*100;
				break;
		}
		
		max_prize = max(max_prize,current_prize);
		
		if( max_prize == MAX_PRIZE )
		{
			break;
		}
	}
	
	cout<<max_prize<<endl;
	
	return	0;
}
