#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,m,t,h,c;

    cin>>n>>m>>t;

    h = t/min(n,m);
    c = t%min(n,m);

    for(int i=1;i<=t/max(n,m);i++)
    {
        int num_of_bugers = i+(t-i*max(n,m))/min(n,m);
        int num_of_cokes = (t-i*max(n,m))%min(n,m);

        if( num_of_cokes<c || ((num_of_cokes==c)&&(num_of_bugers>h)) )
        {
            c = num_of_cokes;
            h = num_of_bugers;
        }
    }

    cout<<h<<' '<<c<<'\n';
    return  0;
}