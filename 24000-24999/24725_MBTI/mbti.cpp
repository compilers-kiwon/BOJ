#include    <iostream>

using namespace std;

#define MAX_SIZE    (200+1)
#define NUM_OF_ATTR 4

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];

const string mbti[NUM_OF_ATTR] = {"EI","NS","FT","PJ"};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

bool    is_mbti(const string& str)
{
    for(int i=0;i<NUM_OF_ATTR;i++)
    {
        if( mbti[i].find(str[i]) == string::npos )
        {
            return  false;
        }
    }

    return  true;
}

int     get_num_of_mbti(int row,int col)
{
    int ret = 0;

    for(int d_row=-1;d_row<=1;d_row++)
    {
        for(int d_col=-1;d_col<=1;d_col++)
        {
            string  mbti;

            for(int i=0;i<NUM_OF_ATTR;i++)
            {
                int adj_row = row+d_row*i;
                int adj_col = col+d_col*i;

                if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
                {
                    break;
                }

                mbti.push_back(grid[adj_row][adj_col]);
            }

            if( mbti.length()==NUM_OF_ATTR && is_mbti(mbti) )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int     simulate(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            ret += get_num_of_mbti(row,col);
        }
    }

    return  ret;
}

int     input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}