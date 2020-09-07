#include	<iostream>

using namespace	std;

#define	MAX_SCORE	18

int	main(void)
{
	double	A[MAX_SCORE+1][MAX_SCORE+1],B[MAX_SCORE+1][MAX_SCORE+1],AB[MAX_SCORE+1][MAX_SCORE+1];
	double	team_A_make_point,team_A_no_point,team_B_make_point,team_B_no_point;
	double	answer;
	
	cin>>team_A_make_point>>team_B_make_point;
	
	team_A_make_point /= 100.0;
	team_B_make_point /= 100.0;
	team_A_no_point = 1.0-team_A_make_point;
	team_B_no_point = 1.0-team_B_make_point;
	
	A[1][0] = team_A_no_point;
	A[1][1] = team_A_make_point;
	B[1][0] = team_B_no_point;
	B[1][1] = team_B_make_point;
	
	for(int i=2;i<=MAX_SCORE;i++)
	{
		A[i][0] = A[i-1][0]*team_A_no_point;
		B[i][0] = B[i-1][0]*team_B_no_point;
		
		for(int j=1;j<i;j++)
		{
			A[i][j] = A[i-1][j-1]*team_A_make_point+A[i-1][j]*team_A_no_point;
			B[i][j] = B[i-1][j-1]*team_B_make_point+B[i-1][j]*team_B_no_point;
		}
		
		A[i][i] = A[i-1][i-1]*team_A_make_point;
		B[i][i] = B[i-1][i-1]*team_B_make_point;
	}
	
	for(int a=0;a<=MAX_SCORE;a++)
	{
		for(int b=0;b<=MAX_SCORE;b++)
		{
			AB[a][b] = A[MAX_SCORE][a]*B[MAX_SCORE][b];
		}
	}
	
	answer = 0.0;
	
	for(int i=0;i<=MAX_SCORE;i++)
	{
		switch(i)
		{
			case	2:
			case	3:
			case	5:
			case	7:
			case	11:
			case	13:
			case	17:
				for(int j=0;j<=MAX_SCORE;j++)
				{
					answer += AB[i][j];
				}
				break;
			default :
				answer += AB[i][2]+AB[i][3]+AB[i][5]+AB[i][7]+AB[i][11]+AB[i][13]+AB[i][17];
		}
	}
		
	printf("%.16f\n",answer);
	
	return	0;
}
