#include	<iostream>
#include	<list>
#include	<string>
#include	<vector>

using namespace	std;

typedef	struct	_ROOM_INFO	Room;
struct	_ROOM_INFO
{
	int		num_of_people,from,size;
	bool	is_empty;
};

int			N,Q;
list<Room>	room_list;

vector<list<Room>::iterator>	allocated;

void	divide_room(int required_size,int num_of_customer)
{
	list<Room>::iterator	it;
	
	for(it=room_list.begin();it!=room_list.end();it++)
	{
		if( it->is_empty==true && it->size>=required_size )
		{
			break;
		}
	}
	
	if( it == room_list.end() )
	{
		cout<<"REJECTED\n";
	}
	else
	{
		Room	tmp;
		
		list<Room>::iterator	tmp_it;
		
		tmp.num_of_people = num_of_customer;
		tmp.from = it->from;
		tmp.size = required_size;
		tmp.is_empty = false;
		
		room_list.insert(it,tmp);
		tmp_it = it;
		tmp_it--;
		allocated.push_back(tmp_it);
		
		if( it->size == required_size )
		{
			room_list.erase(it);
		}
		else
		{
			it->from = it->from+required_size;
			it->size = it->size-required_size;
		}
		
		cout<<tmp.from<<' '<<tmp.from+tmp.size-1<<'\n';
	}
}

void	enter(int room_index,int num_of_customer)
{
	list<Room>::iterator	it;
	int						i;
	
	it = allocated[room_index-1];
	
	it->num_of_people += num_of_customer;
}

void	out(int room_index,int num_of_customer)
{
	list<Room>::iterator	it,left,right,tmp;
	int						i;
	
	it = allocated[room_index-1];
	
	for(i=1,tmp=room_list.begin();tmp!=room_list.end();tmp++,i++)
	{
		if( it == tmp )
		{
			break;
		}
	}
	
	it->num_of_people -= num_of_customer;
	
	if( it->num_of_people == 0 )
	{
		cout<<"CLEAN "<<it->from<<' '<<it->from+it->size-1<<'\n';
		
		int	num_of_rooms;
		
		it->is_empty = true;
		num_of_rooms = room_list.size();
		
		if( i>1 && i<num_of_rooms )
		{
			left = right = it;
			left--;
			right++;
			
			if( left->is_empty==true && right->is_empty==true )
			{
				left->size += it->size+right->size;
				room_list.erase(it);
				room_list.erase(right);
			}
			else if( left->is_empty == true )
			{
				left->size += it->size;
				room_list.erase(it);
			}
			else if( right->is_empty == true )
			{
				it->size += right->size;
				room_list.erase(right);
			}
		}
		else if( i==1 && i<num_of_rooms )
		{
			right = it;
			right++;
			
			if( right->is_empty == true )
			{
				it->size += right->size;
				room_list.erase(right);
			}
		}
		else if( i>1 && i==num_of_rooms )
		{
			left = it;
			left--;
			
			if( left->is_empty == true )
			{
				left->size += it->size;
				room_list.erase(it);
			}
		}
	}
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>Q;
	
	Room r;
	
	r.num_of_people = 0;
	r.from = 1;
	r.size = N;
	r.is_empty = true;
	
	room_list.push_back(r);
	
	for(int i=1;i<=Q;i++)
	{
		string	op;
		int		A,B;
		
		cin>>op>>A>>B;
		
		if( op == "new" )
		{
			divide_room(B,A);
		}
		else if( op == "in" )
		{
			enter(A,B);
		}
		else
		{
			out(A,B);
		}
	}
	
	return	0;
}
