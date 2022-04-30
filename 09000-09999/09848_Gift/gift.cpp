#include    <iostream>

using namespace std;

#define MAX_TIME    100000

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,k,num_of_gifts,prev_time;

    cin>>n>>k;
    num_of_gifts = prev_time = 0;

    for(int i=1;i<=n;i++)
    {
        int t;

        cin>>t;

        if( prev_time-t >= k )
        {
            num_of_gifts++;
        }

        prev_time = t;
    }

    cout<<num_of_gifts<<'\n';

    return  0;
}