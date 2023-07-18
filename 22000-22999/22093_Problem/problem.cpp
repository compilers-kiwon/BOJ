#include    <iostream>

using namespace std;

#define get_min(n,a,b)  (max(0,(a)-(b)))
#define get_max(n,a,b)  ((a)-max(0,(b)-((n)-(a))))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int n,a,b;

        cin>>n>>a>>b;
        cout<<get_min(n,a,b)<<' '<<get_max(n,a,b)<<'\n';
    }

    return  0;
}