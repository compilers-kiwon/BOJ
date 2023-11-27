#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

static int N,M,K;
static vector<string> grid;

static inline void print_grid(void) {
    for (int i=0;i<N;i++) {
        cout<<grid[i]<<'\n';
    }
}

void input(void)
{
    cin>>N>>M>>K;

    for (int i=0;i<N;i++) {
        string  s;
        cin>>s;
        grid.push_back(s);
    }
}

void get_tile_color(int s_row,int s_col,
        int num_of_rows,int num_of_cols,int cnt[])
{
    for (int r=0;r<num_of_rows;r++) {
        for (int c=0;c<num_of_cols;c++) {
            int row = s_row+K*r;
            int col = s_col+K*c;
            cnt[grid[row][col]]++;
        }
    }
}

char get_max_color(int cnt[])
{
    char ret;
    int max_num;

    max_num = 0;

    for (char c='A';c<='Z';c++) {
        if (cnt[c] > max_num) {
            ret = c;
            max_num = cnt[c];
        }
    }

    return  ret;
}

int paint_tile(int s_row,int s_col,
        int num_of_rows,int num_of_cols,int cnt[])
{
    int ret = 0;
    char color = get_max_color(cnt);

    for (int r=0;r<num_of_rows;r++) {
        for (int c=0;c<num_of_cols;c++) {
            int row = s_row+K*r;
            int col = s_col+K*c;
            
            if (grid[row][col] != color) {
                ret++;
                grid[row][col] = color;
            }
        }
    }

    return  ret;
}

int simulate(void)
{
    int ret = 0;
    int row_size = N/K;
    int col_size = M/K;

    for (int cur_row=0;cur_row<K;cur_row++) {
        for (int cur_col=0;cur_col<K;cur_col++) {
            int cnt[0x100] = {0,};
            get_tile_color(cur_row,cur_col,row_size,col_size,cnt);
            ret += paint_tile(cur_row,cur_col,row_size,col_size,cnt);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';
    print_grid();
    
    return  0;
}