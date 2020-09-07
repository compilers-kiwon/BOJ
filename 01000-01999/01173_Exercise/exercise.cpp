#include	<iostream>

using namespace	std;

int	N,m,M,T,R;

int	exercise(int current_exercise_time,int current_pulse,int cnt)
{
	if( current_exercise_time == N )
	{
		return	cnt;
	}
	
	int	next_pulse;
	
	// if do an exercise
	next_pulse = current_pulse+T;
	
	if( next_pulse <= M )
	{
		return	exercise(current_exercise_time+1,next_pulse,cnt+1);
	}
	
	// rest
	next_pulse = max(current_pulse-R,m);
	
	return	exercise(current_exercise_time,next_pulse,cnt+1);
}

int	main(void)
{
	cin>>N>>m>>M>>T>>R;
	
	if( T > M-m )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<exercise(0,m,0)<<endl;
	}
	
	return	0;
}
