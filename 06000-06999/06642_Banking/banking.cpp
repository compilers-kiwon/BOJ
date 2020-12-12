#include	<iostream>
#include	<cstring>
#include	<map>

using namespace	std;

#define	MAX_BANKS			10
#define	MAX_ACCOUNTS		10000

#define	MAX_LEN	8

typedef	pair<int,int>	Account;	// first:available,second:amount

Account	accounts[MAX_BANKS][MAX_ACCOUNTS];

bool	init(int n)
{
	int	A;
	
	scanf("%d",&A);
	
	if( A == 0 )
	{
		return	false;
	}

	for(int i=1;i<=A;i++)
	{
		int		bank_code,account_number,amount1,amount2;
		
		scanf("%d/%d %d.%d",&account_number,&bank_code,&amount1,&amount2);
		accounts[bank_code][account_number] = make_pair(n,amount1*100+amount2);
	}
	
	return	true;
}

void	create(int n,int bank_code,int account_number)
{
	if( accounts[bank_code][account_number].first != n )
	{
		puts("create: ok");
		accounts[bank_code][account_number] = make_pair(n,0);
	}
	else
	{
		puts("create: already exists");
	}
}

void	deposit(int n,int bank_code,int account_number,int amount1,int amount2)
{
	if( accounts[bank_code][account_number].first != n )
	{
		printf("deposit %d.%02d: no such account\n",amount1,amount2);
	}
	else
	{
		printf("deposit %d.%02d: ok\n",amount1,amount2);
		accounts[bank_code][account_number].second += amount1*100+amount2;
	}
}

void	withdraw(int n,int bank_code,int account_number,int amount1,int amount2)
{
	if( accounts[bank_code][account_number].first != n )
	{
		printf("withdraw %d.%02d: no such account\n",amount1,amount2);
	}
	else
	{
		int	t;
		
		t = amount1*100+amount2;
		
		if( accounts[bank_code][account_number].second >= t )
		{
			printf("withdraw %d.%02d: ok\n",amount1,amount2);
			accounts[bank_code][account_number].second -= t;
		}
		else
		{
			printf("withdraw %d.%02d: insufficient funds\n",amount1,amount2);
		}
	}
}

void	transfer(int src_bank_code,int src_account_number,
				 int target_bank_code,int target_account_number,
				 int amount1,int amount2,int n)
{
	if( accounts[src_bank_code][src_account_number].first != n ||
		accounts[target_bank_code][target_account_number].first != n )
	{
		printf("transfer %d.%02d: no such account\n",amount1,amount2);
	}
	else
	{
		if( src_bank_code==target_bank_code &&
			src_account_number==target_account_number )
		{
			printf("transfer %d.%02d: same account\n",amount1,amount2);
		}
		else
		{
			int	t;
			
			t = amount1*100+amount2;
			
			if( accounts[src_bank_code][src_account_number].second >= t )
			{
				accounts[src_bank_code][src_account_number].second -= t;
				accounts[target_bank_code][target_account_number].second += t;
				
				if( src_bank_code == target_bank_code )
				{
					printf("transfer %d.%02d: ok\n",amount1,amount2);
				}
				else
				{
					printf("transfer %d.%02d: interbank\n",amount1,amount2);
				}
			}
			else
			{
				printf("transfer %d.%02d: insufficient funds\n",amount1,amount2);
			}
		}
	}
}

int		main(void)
{
	for(int n=1;;n++)
	{
		if( init(n) == false )
		{
			puts("goodbye");
			break;
		}
		
		for(;;)
		{
			char	command[MAX_LEN+1];
			int		bank1,bank2,num1,num2,a1,a2;
					
			scanf("%s",command);
			
			if( command[0] == 'e' )
			{
				puts("end\n");
				break;
			}
			
			if( command[0] == 'c' )
			{
				scanf("%d/%d",&num1,&bank1);
				create(n,bank1,num1);
				
				continue;
			}
			
			if( command[0] == 'd' )
			{
				scanf("%d/%d %d.%d",&num1,&bank1,&a1,&a2);
				deposit(n,bank1,num1,a1,a2);
				
				continue;
			}
			
			if( command[0] == 'w' )
			{
				scanf("%d/%d %d.%d",&num1,&bank1,&a1,&a2);
				withdraw(n,bank1,num1,a1,a2);
				
				continue;
			}
			
			if( command[0] == 't' )
			{
				scanf("%d/%d %d/%d %d.%d",&num1,&bank1,&num2,&bank2,&a1,&a2);
				transfer(bank1,num1,bank2,num2,a1,a2,n);
				
				continue;
			}
		}
	}
	
	return	0;
}
