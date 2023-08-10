#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define RIGHT   0
#define DOWN    1
#define LEFT    2
#define UP      3
#define MAX_DIR 4
#define MSG_LEN 5
#define EMPTY   ' '

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

#define NEXT_DIR(d)         (((d)+1)%MAX_DIR)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))
#define IN_AREA(r,c,r_max,c_max) \
    (IN_RANGE(0,(r),(r_max))&&IN_RANGE(0,(c),(c_max)))

static string   chr2bin[0x100];

int init(void)
{
    chr2bin[' '] = "00000";

    for (char c='A';c<='Z';c++) {
        for (int i=MSG_LEN-1;i>=0;i--) {
            chr2bin[c].push_back((c&(1<<i))?'1':'0');
        }
    }

    return  0;
}

int input(vector<string>& grid,string& M)
{
    int     R,C;
    string  str;

    getline(cin,str);
    sscanf(str.c_str(),"%d %d",&R,&C);
    
    for (int i=0,cnt=0;;i++) {
        if (str[i]==' ' && ++cnt==2) {
                M = str.substr(i+1);
                break;
            }
    }

    for (int row=0;row<R;row++) {
        grid.push_back(string(C,EMPTY));
    }

    return  0;
}

int encode(const string& src,string& encoded)
{
    for (int i=0;i<src.length();i++) {
        encoded += chr2bin[src[i]];
    }

    return  0;
}

int build_msg(vector<string>& grid,const string& encoded)
{
    int cur_dir,row,col;
    int row_size,col_size;

    row = 0;
    col = -1;
    cur_dir = RIGHT;

    row_size = grid.size();
    col_size = grid.front().length();

    for (int i=0,cnt=0;cnt<row_size*col_size;)
    {
        int adj_row = row+adj[cur_dir].d_row;
        int adj_col = col+adj[cur_dir].d_col;

        if (!IN_AREA(adj_row,adj_col,row_size,col_size)
                || grid[adj_row][adj_col]!=EMPTY) {
            cur_dir = NEXT_DIR(cur_dir);
            continue;
        }

        row = adj_row;
        col = adj_col;
        
        grid[row][col] = (i<encoded.length())?encoded[i]:'0';
        i++,cnt++;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     T;
    string  str;

    getline(cin,str);
    sscanf(str.c_str(),"%d",&T);

    init();

    for (int t=1;t<=T;t++) {
        vector<string>  grid;
        string  src_msg,encoded;

        input(grid,src_msg);
        encode(src_msg,encoded);
        build_msg(grid,encoded);

        for (int i=0;i<grid.size();i++) {
            cout<<grid[i]<<(i==grid.size()-1?"\n":"");
        }
    }

    return  0;
}