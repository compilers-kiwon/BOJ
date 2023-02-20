#include    <iostream>

using namespace std;

#define MAX_HOUR    24
#define MAX_MINUTE  60

typedef pair<int,int>   Digit;

static Digit dh[MAX_HOUR],dm[MAX_MINUTE];

#define is_include(h,m,n) \
    (dm[(m)].first==(n)||dm[(m)].second==(n)||\
            dh[(h)].first==(n)||dh[(h)].second==(n))

#define is_over(h1,m1,h2,m2) \
    (((h1)>(h2))||((h1)==(h2)&&(m1)>(m2)))

int init(void)
{
    for(int i=0;i<MAX_HOUR;i++)
    {
        dh[i] = make_pair(i/10,i%10);
    }

    for(int i=0;i<MAX_MINUTE;i++)
    {
        dm[i] = make_pair(i/10,i%10);
    }

    return  0;
}

int simulate(int current_hour,int current_minute,
                int to_hour,int to_minute,int digit)
{
    int ret = 0;

    for(;!is_over(current_hour,current_minute,to_hour,to_minute);current_minute++)
    {
        if( current_minute == MAX_MINUTE )
        {
            current_hour++;
            current_minute = 0;
        }

        ret += is_include(current_hour,current_minute,digit)?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int from_hour,from_minute;
    int to_hour,to_minute,N;

    cin>>from_hour>>from_minute>>to_hour>>to_minute>>N;
    init();
    cout<<simulate(from_hour,from_minute,to_hour,to_minute,N)<<'\n';

    return  0;
}