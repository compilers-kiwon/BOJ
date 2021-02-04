#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

typedef	struct	_STATE_INFO	State;

struct	_STATE_INFO
{
	vector<string>		accounts;
	double				max_internal_limit,daily_internal_limit;
	double				max_payment_limit,daily_payment_limit;
	map<string,double>	sum_of_daily_internal_transaction;
	map<string,double>	sum_of_daily_payment_transaction;
};

map<string,State>	customer_state;

void	parse(string& str,vector<string>& result)
{
	string	tmp;
	
	str.push_back(',');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ',' )
		{
			result.push_back(tmp);
			tmp.clear();
		}
		else
		{
			tmp.push_back(str[i]);
		}
	}
}

#define	NAME			1
#define	MAX_IAT_LIMIT	2
#define	DAILY_IAT_LIMIT	3
#define	MAX_PAY_LIMIT	4
#define	DAILY_PAY_LIMIT	5

void	process_customer_record(const vector<string>& record)
{
	State	s;

	sscanf(record[MAX_IAT_LIMIT].c_str(),"%lf",&s.max_internal_limit);
	sscanf(record[DAILY_IAT_LIMIT].c_str(),"%lf",&s.daily_internal_limit);
	sscanf(record[MAX_PAY_LIMIT].c_str(),"%lf",&s.max_payment_limit);
	sscanf(record[DAILY_PAY_LIMIT].c_str(),"%lf",&s.daily_payment_limit);
	
	customer_state[record[NAME]] = s;
}

#define	ACCOUNT_NUMBER	2

void	process_account_record(const vector<string>& record)
{
	vector<string>&	customer_accounts = customer_state[record[NAME]].accounts;
	
	customer_accounts.push_back(record[ACCOUNT_NUMBER]);	
}

#define	DATE	1
#define	OWNER	2
#define	SOURCE	3
#define	AMOUNT	4
#define	DEST	5

void	process_internal_transaction(const vector<string>& record)
{
	bool	instruction_limit_ok,daily_limit_ok;
	string	date;
	double	amount;
		
	date = record[DATE].substr(0,8);
	sscanf(record[AMOUNT].c_str(),"%lf",&amount);
	
	double&	i_limit = customer_state[record[OWNER]].max_internal_limit;
	double&	d_limit = customer_state[record[OWNER]].daily_internal_limit;
	
	if( amount > i_limit )
	{
		instruction_limit_ok = false;
	}
	else
	{
		instruction_limit_ok = true;
	}
	
	double&	daily_transaction = 
		customer_state[record[OWNER]].sum_of_daily_internal_transaction[date];
	
	if( daily_transaction+amount > d_limit )
	{
		daily_limit_ok = false;
	}
	else
	{
		daily_limit_ok = true;
	}
	
	if( instruction_limit_ok && daily_limit_ok )
	{
		daily_transaction += amount;
		cout<<"IAT OK\n";
	}
	else
	{
		if( !instruction_limit_ok )
		{
			cout<<"IAT MAX EXCEEDED\n";
		}
		else
		{
			cout<<"IAT DEL EXCEEDED\n";
		}
	}
}

void	process_payment_transaction(const vector<string>& record)
{
	bool	instruction_limit_ok,daily_limit_ok;
	string	date;
	double	amount;
		
	date = record[DATE].substr(0,8);
	sscanf(record[AMOUNT].c_str(),"%lf",&amount);
	
	double&	i_limit = customer_state[record[OWNER]].max_payment_limit;
	double&	d_limit = customer_state[record[OWNER]].daily_payment_limit;
	
	if( amount > i_limit )
	{
		instruction_limit_ok = false;
	}
	else
	{
		instruction_limit_ok = true;
	}
	
	double&	daily_transaction =
		customer_state[record[OWNER]].sum_of_daily_payment_transaction[date];
	
	if( daily_transaction+amount > d_limit )
	{
		daily_limit_ok = false;
	}
	else
	{
		daily_limit_ok = true;
	}
	
	if( instruction_limit_ok && daily_limit_ok )
	{
		daily_transaction += amount;
		cout<<"PAYMENT OK\n";
	}
	else
	{
		if( !instruction_limit_ok )
		{
			cout<<"PAYMENT MAX EXCEEDED\n";
		}
		else
		{
			cout<<"PAYMENT DEL EXCEEDED\n";
		}
	}
}

bool	find_account(const vector<string>& accounts,const string& number)
{
	for(int i=0;i<accounts.size();i++)
	{
		if( accounts[i] == number )
		{
			return	true;
		}
	}
	
	return	false;
}

bool	is_owned_account(const string& owner,const string& number)
{
	return	find_account(customer_state[owner].accounts,number);
}

#define	INTERNAL	0
#define	PAYMENT		1

int		check_transaction_type(const string& owner,const string& number)
{
	int	ret;
	
	if( find_account(customer_state[owner].accounts,number) == true )
	{
		ret = INTERNAL;
	}
	else
	{
		ret = PAYMENT;
	}
	
	return	ret;
}

void	process_transaction_record(const vector<string>& record)
{
	if( is_owned_account(record[OWNER],record[SOURCE]) == false )
	{
		cout<<"NOT OWNER\n";
		return;
	}
	
	if( check_transaction_type(record[OWNER],record[DEST]) == INTERNAL )
	{
		process_internal_transaction(record);
	}
	else
	{
		process_payment_transaction(record);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int cnt=0;;)
	{
		string			str;
		vector<string>	record;
		
		cin>>str;
		parse(str,record);
		
		if( record.front() == "1" )
		{
			process_customer_record(record);
			continue;
		}
		
		if( record.front() == "2" )
		{
			process_account_record(record);
			continue;
		}
		
		if( record.front() == "9" )
		{
			break;
		}
		
		cout<<"INSTRUCTION "<<++cnt<<": ";
		process_transaction_record(record);
	}
	
	return	0;
}
