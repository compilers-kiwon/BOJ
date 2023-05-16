#include    <iostream>

using namespace std;

int simulate(void)
{
    int N,house,ret;

    cin>>N;
    house = ret = 0;

    for(int i=1;i<=N;i++)
    {
        int in,out;

        cin>>in>>out;
        house += in-out;

        if( house < 0 )
        {
            ret += -house;
            house = 0;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        cout<<simulate()<<'\n';
    }

    return  0;
}