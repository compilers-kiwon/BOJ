#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_TOWN	(100+1)

void	input(int& num_of_towns,int& office_town,int& num_of_employee,
			  int* num_of_employee_in_town,priority_queue<int>* num_of_passengers)
{
	cin>>num_of_towns>>office_town>>num_of_employee;
	
	for(int i=1;i<=num_of_employee;i++)
	{
		int	H,P;
		
		cin>>H>>P;
		
		if( P != 0 )
		{
			num_of_passengers[H].push(P);
		}
		
		num_of_employee_in_town[H]++;
	}
}

int		can_drive(int num_of_employee,priority_queue<int>& dq)
{
	int	cnt,sum;
	
	for(cnt=1,sum=0;!dq.empty();cnt++)
	{
		sum += dq.top();
		dq.pop();
		
		if( sum >= num_of_employee )
		{
			return	cnt;
		}
	}
	
	return	0;
}

bool	move(int& num_of_towns,int& office_town,int* table,
			 int* num_of_employee_in_town,priority_queue<int>* num_of_passengers)
{
	bool	result;
	
	result = true;
	
	for(int i=1;i<=num_of_towns;i++)
	{
		if( i==office_town || num_of_employee_in_town[i]==0 )
		{
			table[i] = 0;
			continue;
		}
		
		int	num_of_cars;
		
		num_of_cars = can_drive(num_of_employee_in_town[i],num_of_passengers[i]);
		
		if( num_of_cars != 0 )
		{
			table[i] = num_of_cars;
		}
		else
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	C;
	
	cin>>C;
	
	for(int i=1;i<=C;i++)
	{
		int					N,T,E;
		int					num_of_employee_in_town[MAX_NUM_OF_TOWN];
		int					drive_table[MAX_NUM_OF_TOWN];
		priority_queue<int>	num_of_passengers[MAX_NUM_OF_TOWN];
		
		for(int j=1;j<=N;j++)
		{
			num_of_employee_in_town[j] = 0;
		}
		
		input(N,T,E,num_of_employee_in_town,num_of_passengers);
		
		cout<<"Case #"<<i<<": ";
		
		if( move(N,T,drive_table,num_of_employee_in_town,num_of_passengers) == false )
		{
			cout<<"IMPOSSIBLE\n";
		}
		else
		{
			for(int j=1;j<N;j++)
			{
				cout<<drive_table[j]<<' ';
			}
			cout<<drive_table[N]<<'\n';
		}
	}
	
	return	0;
}
