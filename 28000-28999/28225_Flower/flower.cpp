#include    <iostream>
#include    <cfloat>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,c;
    double  f,min_time;

    cin>>n>>f;
    min_time = f;

    for (int i=1;i<=n;i++) {
        double  x,v,arrival_time;

        cin>>x>>v;
        if ((arrival_time=(f-x)/v) < min_time) min_time=arrival_time,c=i;
    }

    cout<<c<<'\n';
    return  0;
}