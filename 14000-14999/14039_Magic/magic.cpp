#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    4

typedef long long int int64;
typedef struct{int d_row,d_col;} Offset;

static int64 square[MAX_SIZE+1][MAX_SIZE+1];

#define RIGHT   {0,1}
#define DOWN    {1,0}

int64 get_sum(int s_row,int s_col,Offset o)
{
    int64 ret = 0;

    for (int i=0;i<MAX_SIZE;i++) {
        int row = s_row+o.d_row*i;
        int col = s_col+o.d_col*i;

        ret += square[row][col];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int row=1;row<=MAX_SIZE;row++) {
        for (int col=1;col<=MAX_SIZE;col++) {
            cin>>square[row][col];
        }
    }

    set<int64>  sum;

    for (int row=1;row<=MAX_SIZE;row++) {
        sum.insert(get_sum(row,1,RIGHT));
    }

    for (int col=1;col<=MAX_SIZE;col++) {
        sum.insert(get_sum(1,col,DOWN));
    }

    cout<<(sum.size()==1?"magic":"not magic")<<'\n';
    return  0;
}