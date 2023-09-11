#include    <iostream>

using namespace std;

#define ROW_SIZE        (6)
#define COL_SIZE        (9)
#define NUM_OF_GRIDS    (2)
#define NUM_OF_COLORS   (3)

static char flag[ROW_SIZE+1][COL_SIZE+2];

const struct{int top,bottom,left,right;} 
    grid[NUM_OF_GRIDS][NUM_OF_COLORS] = {
        {{1,2,1,9},{3,4,1,9},{5,6,1,9}},
        {{1,6,1,3},{1,6,4,6},{1,6,7,9}}
};

int fill_flag(int g_idx,int c_idx,char c)
{
    int ret = 0;
    
    int top = grid[g_idx][c_idx].top;
    int bottom = grid[g_idx][c_idx].bottom;
    int left = grid[g_idx][c_idx].left;
    int right = grid[g_idx][c_idx].right;

    for(int row=top;row<=bottom;row++)
    {
        for(int col=left;col<=right;col++)
        {
            ret += (flag[row][col]!=c)?1:0;
        }
    }

    return  ret;
}

int simulate(void)
{
    int ret = 0x7FFFFFFF;

    for(char top='A';top<='Z';top++)
    {
        for(char mid='A';mid<='Z';mid++)
        {
            for(char bottom='A';bottom<='Z';bottom++)
            {
                if(top==mid || mid==bottom)
                {
                    continue;
                }

                int sum1 = fill_flag(0,0,top)+
                        fill_flag(0,1,mid)+fill_flag(0,2,bottom);
                int sum2 = fill_flag(1,0,top)+
                        fill_flag(1,1,mid)+fill_flag(1,2,bottom);
                
                ret = min(ret,min(sum1,sum2));
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int row=1;row<=ROW_SIZE;row++)
    {
        cin>>&flag[row][1];
    }

    cout<<simulate()<<'\n';
    return  0;
}