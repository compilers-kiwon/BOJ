#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int n,prev_time,s,t,total_distance;

        cin>>n;

        if( n == -1 )
        {
            break;
        }

        prev_time = total_distance = 0;

        for(int i=1;i<=n;i++)
        {
            cin>>s>>t;

            total_distance += (t-prev_time)*s;
            prev_time = t;
        }

        cout<<total_distance<<" miles\n";
    }

    return  0;
}