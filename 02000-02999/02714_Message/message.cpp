#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define RIGHT   0
#define DOWN    1
#define LEFT    2
#define UP      3
#define MAX_DIR 4

#define NEXT_DIR(d) (((d)+1)%MAX_DIR)

const string num2chr = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

#define IN_AREA(r,c,r_max,c_max) \
    (IN_RANGE(0,(r),(r_max))&&IN_RANGE(0,(c),(c_max)))

#define VISITED ' '
#define MSG_LEN 5

#define get_decimal_from_binary(num)    (stoi((num),nullptr,2))

int input(vector<string>& grid)
{
    int     R,C;
    string  M;

    cin>>R>>C>>M;
    
    for(int row=0;row<R;row++)
    {
        grid.push_back(M.substr(row*C,C));
    }

    return  0;
}

int decode(vector<string>& grid,string& result)
{
    int cur_dir,row,col;
    int row_size,col_size;
    string  encoded;

    row = 0;
    col = -1;
    cur_dir = RIGHT;

    row_size = grid.size();
    col_size = grid.front().length();

    for(int cnt=0;cnt<row_size*col_size;)
    {
        int adj_row = row+adj[cur_dir].d_row;
        int adj_col = col+adj[cur_dir].d_col;

        if( !IN_AREA(adj_row,adj_col,row_size,col_size)
            || grid[adj_row][adj_col]==VISITED )
        {
            cur_dir = NEXT_DIR(cur_dir);
            continue;
        }

        row = adj_row;
        col = adj_col;
        cnt++;

        encoded.push_back(grid[row][col]);
        grid[row][col] = VISITED;

        if( encoded.length() == MSG_LEN )
        {
            result.push_back(num2chr[get_decimal_from_binary(encoded)]);
            encoded.clear();
        }
    }

    return  0;
}

int remove_tail_space(string& str)
{
    for(;!str.empty()&&str.back()==' ';str.pop_back());
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        vector<string>  grid;
        string  decoded_msg;

        input(grid);
        decode(grid,decoded_msg);

        remove_tail_space(decoded_msg);
        cout<<decoded_msg<<'\n';
    }

    return  0;
}