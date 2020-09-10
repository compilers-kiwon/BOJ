#include	<iostream>
#include	<queue>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(10+1)

typedef	pair<int,int>	Pos;

void	rotate(queue<Pos>&	pos_q,int grid_size)
{
	for(int i=1,size=pos_q.size();i<=size;i++)
	{
		int	current_row,current_col;
		int	next_row,next_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		next_row = current_col;
		next_col = grid_size-current_row+1;
		
		pos_q.pop();
		pos_q.push(make_pair(next_row,next_col));
	}
}

void	decrypt_msg(string& msg,int& index,queue<Pos>& pos_q,char decrypted[][MAX_SIZE])
{
	vector<Pos>	pos_vec;
	
	for(int i=1,size=pos_q.size();i<=size;i++)
	{
		Pos	p;
		
		p = pos_q.front();
		pos_q.pop();
		
		
		pos_vec.push_back(p);
		pos_q.push(p);
	}
	
	sort(pos_vec.begin(),pos_vec.end());
	
	for(int i=0;i<pos_vec.size();i++)
	{
		Pos&	p = pos_vec[i];
		
		decrypted[p.first][p.second] = msg[index];
		index++;
	}
}

int		main(void)
{
	int			n,idx;
	string		m,outbuf;
	queue<Pos>	grille;
	char		decrypted[MAX_SIZE][MAX_SIZE];
	
	cin>>n;
	
	for(int row=1;row<=n;row++)
	{
		string	str;
		
		cin>>str;
		str.insert(str.begin(),' ');
		
		for(int col=1;col<=n;col++)
		{
			if( str[col] == '.' )
			{
				grille.push(make_pair(row,col));
			}
			
			decrypted[row][col] = '\0';
		}
	}
	
	cin>>m;
	idx = 0;
	
	decrypt_msg(m,idx,grille,decrypted);
	
	rotate(grille,n);
	decrypt_msg(m,idx,grille,decrypted);
	
	rotate(grille,n);
	decrypt_msg(m,idx,grille,decrypted);
	
	rotate(grille,n);
	decrypt_msg(m,idx,grille,decrypted);
	
	bool	is_valid;
	
	is_valid = true;
	
	for(int row=1;row<=n&&is_valid!=false;row++)
	{
		for(int col=1;col<=n&&is_valid!=false;col++)
		{
			if( decrypted[row][col] == '\0' )
			{
				is_valid = false;
			}
			else
			{
				outbuf.push_back(decrypted[row][col]);
			}
		}
	}
	
	if( is_valid == true )
	{
		cout<<outbuf<<'\n';
	}
	else
	{
		cout<<"invalid grille\n";
	}
	
	return	0;
}
