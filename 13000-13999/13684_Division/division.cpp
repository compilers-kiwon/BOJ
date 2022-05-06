#include    <iostream>
#include    <string>

using namespace std;

#define MAX_NUM_OF_NATIONS  4

const string    nation[MAX_NUM_OF_NATIONS+1] = {"NO","NE","SE","SO","divisa"};

int find_nation(int div_X,int div_Y,int cur_X,int cur_Y)
{
    int ret = 0;

    if( cur_X<div_X && cur_Y>div_Y)
    {
        return  ret;
    }

    ++ret;

    if( cur_X>div_X && cur_Y>div_Y)
    {
        return  ret;
    }

    ++ret;

    if( cur_X>div_X && cur_Y<div_Y)
    {
        return  ret;
    }

    ++ret;

    if( cur_X<div_X && cur_Y<div_Y)
    {
        return  ret;
    }

    ++ret;

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int K;

        cin>>K;

        if( K == 0 )
        {
            break;
        }

        int N,M;

        cin>>N>>M;

        for(int i=1;i<=K;i++)
        {
            int X,Y;

            cin>>X>>Y;
            cout<<nation[find_nation(N,M,X,Y)]<<'\n';
        }
    }

    return  0;
}