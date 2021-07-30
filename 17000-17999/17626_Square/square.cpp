#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_NUM     50000
#define MAX_SIZE    3

int         cnt[MAX_NUM+1];
vector<int> square[MAX_SIZE+1];

void    build_cnt_table(void)
{
    for(int i=1;i*i<=MAX_NUM;i++)
    {
        cnt[i*i] = 1;
        square[1].push_back(i*i);
    }

    for(int i=0;i<square[1].size();i++)
    {
        for(int j=i;j<square[1].size();j++)
        {
            int n = square[1][i]+square[1][j];

            if( n > MAX_NUM )
            {
                break;
            }

            int&    c = cnt[n];

            if( c == 0 )
            {
                c = 2;
                square[2].push_back(n);
            }
        }
    }

    for(int i=0;i<square[1].size();i++)
    {
        for(int j=0;j<square[2].size();j++)
        {
            int n = square[1][i]+square[2][j];

            if( n > MAX_NUM )
            {
                continue;
            }

            int&    c = cnt[n];

            if( c == 0 )
            {
                c = 3;
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;
    build_cnt_table();

    cout<<(cnt[n]==0?4:cnt[n])<<'\n';

    return  0;
}