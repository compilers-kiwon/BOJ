#include    <iostream>

using namespace std;

#define MAX_NUM_OF_SHIPS    (200+1)

typedef pair<int,int>   Ship;   // first:distance,second:value

int get_available_value(int num_of_ships,int speed,
                            int remainig_days,Ship s[])
{
    int ret = 0;
    int reachable_distance = speed*remainig_days;

    for(int i=1;i<=num_of_ships;i++)
    {
        int&    d = s[i].first;
        int&    v = s[i].second;

        if( d <= reachable_distance )
        {
            ret += v;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int K;

    cin>>K;

    for(int i=1;i<=K;i++)
    {
        int     n,s,d;
        Ship    sh[MAX_NUM_OF_SHIPS];

        cin>>n>>s>>d;

        for(int j=1;j<=n;j++)
        {
            cin>>sh[j].first>>sh[j].second;
        }

        cout<<"Data Set "<<i<<":\n"<<
                get_available_value(n,s,d,sh)<<"\n\n";
    }

    return  0;
}