#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     L;
    float   C,total_cost;

    cin>>C>>L;
    total_cost = 0.0;

    for(int i=1;i<=L;i++)
    {
        float   w,l;

        cin>>w>>l;
        total_cost += w*l*C;
    }

    cout.setf(ios::fixed);cout.precision(6);
    cout<<total_cost<<'\n';

    return  0;
}