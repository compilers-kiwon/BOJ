#include    <iostream>
#include    <string>
#include    <cmath>
#include    <map>

using namespace std;

#define get_sign(n) (((n)>0.0)?1:-1)

static map<pair<int,int>,string> Q = {
    {{1,1},"Q1"},{{-1,1},"Q2"},{{-1,-1},"Q3"},{{1,-1},"Q4"}
};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        double  x,y;

        cin>>x>>y;
        cout<<((x==0.0||y==0.0)?"AXIS":
                Q[{get_sign(x),get_sign(y)}])<<'\n';

        if( x==0.0 && y==0.0 )
        {
            break;
        }
    }

    return  0;
}