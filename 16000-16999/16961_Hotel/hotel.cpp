#include    <iostream>

using namespace std;

#define NUM_OF_DAYS 366

#define tab     first
#define space   second

static pair<int,int>    cnt[NUM_OF_DAYS+1];

#define is_fight(s,t)   (((s)==0||(t)==0)||((s)!=(t)))

int get_num_of_days_with_guest(void)
{
    int ret = 0;

    for(int i=1;i<=NUM_OF_DAYS;i++)
    {
        ret += (cnt[i].tab||cnt[i].space)?1:0;
    }

    return  ret;
}

int get_day_with_max_guests(void)
{
    int ret = 0;

    for(int i=1;i<=NUM_OF_DAYS;i++)
    {
        ret = max(ret,cnt[i].tab+cnt[i].second);
    }

    return  ret;
}

int get_num_of_days_without_fight(void)
{
    int ret = 0;

    for(int i=1;i<=NUM_OF_DAYS;i++)
    {
        ret += !is_fight(cnt[i].space,cnt[i].tab)?1:0;
    }

    return  ret;
}

int get_max_num_of_guests_without_fight(void)
{
    int ret = 0;

    for(int i=1;i<=NUM_OF_DAYS;i++)
    {
        int&    s = cnt[i].space;
        int&    t = cnt[i].tab;

        ret = max(ret,!is_fight(s,t)?s+t:0);;
    }

    return  ret;
}

int input(void)
{
    int N,ret;

    cin>>N;
    ret = 0;

    for(int i=1;i<=N;i++)
    {
        char    c;
        int     s,e,days;

        cin>>c>>s>>e;
        ret = max(ret,e-s+1);

        for(int i=s;i<=e;i++)
        {
            (c=='T')?cnt[i].tab++:cnt[i].space++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int longest_stay_days = input();

    cout<<get_num_of_days_with_guest()<<'\n';
    cout<<get_day_with_max_guests()<<'\n';
    cout<<get_num_of_days_without_fight()<<'\n';
    cout<<get_max_num_of_guests_without_fight()<<'\n';
    cout<<longest_stay_days<<'\n';

    return  0;
}