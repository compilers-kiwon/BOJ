#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    3
#define MAX_DIR     4

int     N,M;
char    grid[MAX_SIZE][MAX_SIZE+1];
bool    visited[MAX_SIZE][MAX_SIZE];

#define char2int(c) ((int)((c)-'0'))

typedef pair<int,int>   Pos;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

#define get_sign(p) ((grid[(p).first][(p).second]=='+')?1:-1)
#define get_num(p)  (char2int(grid[(p).first][(p).second]))

#define get_pos(dst,src,dir)    \
    {(dst).first=(src).first+adj[(dir)].d_row,\
        (dst).second=(src).second+adj[(dir)].d_col;}
        
#define IN_AREA(pos)    \
    (IN_RANGE(0,(pos).first,MAX_SIZE)&&IN_RANGE(0,(pos).second,MAX_SIZE))

#define is_visited(pos)     (visited[(pos).first][(pos).second]==true)
#define mark_visited(pos,v) (visited[(pos).first][(pos).second]=(v))

#define entry_sequence(pos,vec) \
    {mark_visited((pos),true);(vec).push_back(pos);}

#define exit_sequence(pos,vec) \
    {mark_visited((pos),false);(vec).pop_back();}

bool    dfs(int current_value,vector<Pos>& p)
{
    if( p.size() == (2*M-1) )
    {
        return  (current_value==N);
    }

    int tmp;
    Pos sign_pos,num_pos;

    for(int d1=0;d1<MAX_DIR;d1++)
    {
        get_pos(sign_pos,p.back(),d1);
        
        if( !IN_AREA(sign_pos) || is_visited(sign_pos) )
        {
            continue;
        }

        entry_sequence(sign_pos,p);

        for(int d2=0;d2<MAX_DIR;d2++)
        {
            get_pos(num_pos,sign_pos,d2);
            
            if( !IN_AREA(num_pos) || is_visited(num_pos) )
            {
                continue;
            }

            tmp = get_sign(sign_pos)*get_num(num_pos);

            entry_sequence(num_pos,p);

            if( dfs(current_value+tmp,p) == true )
            {
                return  true;
            }

            exit_sequence(num_pos,p);
        }

        exit_sequence(sign_pos,p);
    }

    return  false;
}

void    input(void)
{
    cin>>N>>M;

    for(int row=0;row<MAX_SIZE;row++)
    {
        cin>>&grid[row][0];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int row=0;row<MAX_SIZE;row++)
    {
        for(int col=0;col<MAX_SIZE;col++)
        {
            char&   c = grid[row][col];

            if( c=='+' || c=='-' )
            {
                continue;
            }

            vector<Pos> p;

            entry_sequence(make_pair(row,col),p);

            if( dfs(char2int(c),p) == true )
            {
                cout<<"1\n";

                for(int i=0;i<p.size();i++)
                {
                    cout<<p[i].first<<' '<<p[i].second<<'\n';
                }

                return  0;
            }

            exit_sequence(make_pair(row,col),p);
        }
    }

    cout<<"0\n";

    return  0;
}