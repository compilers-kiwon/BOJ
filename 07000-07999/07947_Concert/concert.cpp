#include    <iostream>

using namespace std;

#define MAX_NUM_OF_LIGHTS   10
#define SCALER              5

void    input(int& sr,int& sg,int& sb)
{
    sr = sg = sb = 0;

    for(int i=1;i<=MAX_NUM_OF_LIGHTS;i++)
    {
        int r,g,b;

        cin>>r>>g>>b;

        sr += r;
        sg += g;
        sb += b;
    }
}

void    get_avg(int& r,int& g,int& b)
{
    r = (r+SCALER)/MAX_NUM_OF_LIGHTS;
    g = (g+SCALER)/MAX_NUM_OF_LIGHTS;
    b = (b+SCALER)/MAX_NUM_OF_LIGHTS;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int n=1;n<=N;n++)
    {
        int r,g,b;

        input(r,g,b);
        get_avg(r,g,b);

        cout<<r<<' '<<g<<' '<<b<<'\n';
    }

    return  0;
}