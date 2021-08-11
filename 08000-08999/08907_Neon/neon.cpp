#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

#define BLUE        0
#define RED         1
#define MAX_COLOR   2

int     N,cnt[MAX_SIZE][MAX_COLOR];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cnt[i][BLUE] = cnt[i][RED] = 0;
    }

    for(int v1=1;v1<N;v1++)
    {
        for(int v2=v1+1;v2<=N;v2++)
        {
            int c;

            cin>>c;
            cnt[v1][c]++;cnt[v2][c]++;
        }
    }
}

int     get_num_of_different_color(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret += cnt[i][BLUE]*cnt[i][RED];
    }

    return  ret;
}

int     get_combination(int n,int m)
{
    int ret = 1;

    for(int i=0;i<m;i++)
    {
        ret *= (n-i);
    }

    for(int i=1;i<=m;i++)
    {
        ret /= i;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int different_color;

        input();
        
        different_color = get_num_of_different_color();
        cout<<get_combination(N,3)-different_color/2<<'\n';
    }

    return  0;
}