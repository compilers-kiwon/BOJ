#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int n,m,k,p,h,s;

        cin>>n>>m>>k;

        if( n+m+k == 0 )
        {
            break;
        }

        p = n-(m+k);
        h = n/2+1;

        s = max(h-m,0);
        cout<<((s<=p)?s:-1)<<'\n';
    }

    return  0;
}