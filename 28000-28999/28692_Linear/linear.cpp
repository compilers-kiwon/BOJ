#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    long double  nd,s_x,s_y,s_xx,s_xy,a,b;

    cin>>n;
    s_x = s_y = s_xx = s_xy = 0.0;

    for (int i=1;i<=n;i++) {
        long double x,y;

        cin>>x>>y;
       
        s_x += x;
        s_y += y;
        s_xx += x*x;
        s_xy += x*y;
    }

    nd = (long double)n;

    if (s_x*s_x == nd*s_xx) {
        cout<<"EZPZ\n";
        return  0;
    }
    
    a = (nd*s_xy-s_x*s_y)/(nd*s_xx-s_x*s_x);
    b = (s_y-a*s_x)/nd;

    cout<<fixed;cout.precision(7);
    cout<<a<<' '<<b<<'\n';
    
    return  0;
}