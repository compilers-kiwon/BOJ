#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_ROW	0x100
#define	MAX_COL	100

typedef	pair<string,int>	Friend;		// first:name, second:index
typedef	pair<int,int>		Relation;	// first:index, second:index

int		get_second_idx(const string& name)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<name.length();i++)
	{
		ret += (int)name[i];
	}
	
	return	(ret%MAX_COL);
}

int		get_index(int& cnt,vector<Friend> t[][MAX_COL],string& name)
{
	vector<Friend>&				f = t[name[0]][get_second_idx(name)];
	vector<Friend>::iterator	it;
	
	int	ret;
	
	for(it=f.begin();it!=f.end();it++)
	{
		if( it->first == name )
		{
			break;
		}
	}
	
	if( it != f.end() )
	{
		ret = it->second;
	}
	else
	{
		f.push_back(make_pair(name,cnt));
		
		ret = cnt;
		cnt++;
	}
	
	return	ret;
}

int		input(vector<Relation>& r,vector<Friend> t[][MAX_COL])
{
	int	cnt,F,i;
	
	cin>>F;
	
	for(i=1,cnt=0;i<=F;i++)
	{
		string	id1,id2;
		int		id1_index,id2_index;
		
		cin>>id1>>id2;
		
		id1_index = get_index(cnt,t,id1);
		id2_index = get_index(cnt,t,id2);
		
		r.push_back(make_pair(min(id1_index,id2_index),max(id1_index,id2_index))); 	
	}
	
	return	cnt;	
}

int		find_parent(int idx,vector<int>& p)
{
	if( p[idx] == -1 )
	{
		return	idx;	
	}
	
	p[idx] = find_parent(p[idx],p);
	
	return	p[idx];	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int	num_of_people;
		
		vector<Relation>	rel_vec;
		vector<Friend>		friend_table[MAX_ROW][MAX_COL];
		vector<int>			parent,size_of_nw;
		
		num_of_people = input(rel_vec,friend_table);
		
		parent.resize(num_of_people,-1);
		size_of_nw.resize(num_of_people,1);
		
		for(int i=0;i<rel_vec.size();i++)
		{
			int&	id1 = rel_vec[i].first;
			int&	id2 = rel_vec[i].second;
			int		p1,p2;
			
			p1 = find_parent(id1,parent);
			p2 = find_parent(id2,parent);
			
			if( p1 == p2 )
			{
				cout<<size_of_nw[p1]<<'\n';
			}
			else
			{
				if( p1 < p2 )
				{
					parent[p2] = p1;
					size_of_nw[p1] += size_of_nw[p2];
					
					cout<<size_of_nw[p1]<<'\n';
				}
				else
				{
					parent[p1] = p2;
					size_of_nw[p2] += size_of_nw[p1];
					
					cout<<size_of_nw[p2]<<'\n';
				}
			}
		}
	}
	
	return	0;
}
