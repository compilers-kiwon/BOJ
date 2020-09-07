#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_ITEMS	(100+1)
#define	OFFSET				((int)('a'-'A'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_ITEM_INFO	Item;
struct	_ITEM_INFO
{
	int		num_of_items;
	double	normal_price,club_card_price;
	string	name;		
};

typedef	struct	_PURCHASE_INFO	Purchase;
struct	_PURCHASE_INFO
{
	int		quantity;
	string	name;
};

int			N,M;
Item		item[MAX_NUM_OF_ITEMS];
Purchase	purchase[MAX_NUM_OF_ITEMS];

int		str2int(string& str)
{
	int	ret;
	
	sscanf(str.c_str(),"%d",&ret);
	
	return	ret;
}

double	str2double(string& str)
{
	double	ret;
	
	str.erase(0,1);
	sscanf(str.c_str(),"%lf",&ret);
	
	return	ret;
}

void	input(void)
{
	cin>>N>>M;
	getchar();
	
	for(int i=1;i<=N;i++)
	{
		string	str,tmp;
		int		ptr;
		
		getline(cin,str);
				
		for(ptr=0;str[ptr]!=' ';ptr++)
		{
			tmp.push_back(str[ptr]);
		}
		
		item[i].num_of_items = str2int(tmp);
		tmp.clear();
		
		for(ptr++;str[ptr]!=' ';ptr++)
		{
			tmp.push_back(str[ptr]);
		}
		
		item[i].normal_price = str2double(tmp);
		tmp.clear();
		
		for(ptr++;str[ptr]!=' ';ptr++)
		{
			tmp.push_back(str[ptr]);
		}
		
		item[i].club_card_price = str2double(tmp);
		tmp.clear();
		
		for(ptr++;ptr<str.length();ptr++)
		{
			if( IN_RANGE('a',str[ptr],'z') == true )
			{
				str[ptr] -= OFFSET;
			}
			
			tmp.push_back(str[ptr]);
		}
		
		item[i].name = tmp;
	}
	
	for(int i=1;i<=M;i++)
	{
		string	str,tmp;
		int		ptr;
		
		getline(cin,str);
		
		for(ptr=0;str[ptr]!=' ';ptr++)
		{
			tmp.push_back(str[ptr]);
		}
		
		purchase[i].quantity = str2int(tmp);
		tmp.clear();
		
		for(ptr++;ptr<str.length();ptr++)
		{
			if( IN_RANGE('a',str[ptr],'z') == true )
			{
				str[ptr] -= OFFSET;
			}
			
			tmp.push_back(str[ptr]);
		}
		
		purchase[i].name = tmp;
	}
}

double	get_saved_dollar(void)
{
	double	ret;
	
	ret = 0.0;
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if( purchase[i].name == item[j].name )
			{
				ret += (double)(min(purchase[i].quantity,item[j].num_of_items))
						*(item[j].normal_price-item[j].club_card_price);
				break;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		input();
		printf("Data Set %d:\n$%.02f\n\n",k,get_saved_dollar());
	}
	
	return	0;
}
