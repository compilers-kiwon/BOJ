#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

static inline bool in_range(int MIN,int n,int MAX) {
    return  (MIN<=n && n<=MAX);
}

static inline bool is_square(int n) {
    return  (n == ((int)sqrt(n)*(int)sqrt(n)));
}

const static int MAX_SIZE = 9+1;

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];

int get_num(int row,int col,int row_offset,int col_offset)
{
    string  num;
    int ret = -1;

    if (row_offset==0 && col_offset==0) {
        return  -1;
    }

    for (;in_range(1,row,N)&&in_range(1,col,M);
            row+=row_offset,col+=col_offset) {
        num.push_back(grid[row][col]);
        if (is_square(stoi(num))) ret=stoi(num);
    }

    return  ret;
}

int simulate(void)
{
    int ret = -1;

    for (int row_offset=-N;row_offset<=N;row_offset++) {
        for (int col_offset=-M;col_offset<=M;col_offset++) {
            for (int row=1;row<=N;row++) {
                for (int col=1;col<=M;col++) {
                    int num = get_num(row,col,row_offset,col_offset);
                    ret = max(ret,num);
                }
            }
        }
    }
    
    return  ret;
}

void input(void)
{
    cin>>N>>M;

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            cin>>grid[row][col];
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}