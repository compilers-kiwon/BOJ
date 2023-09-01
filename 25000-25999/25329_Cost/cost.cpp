#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>
#include    <algorithm>

using namespace std;

typedef pair<string,int>    User;

static int  n;
static map<string,int>  call;
static vector<User>     u;

#define get_minutes(t) \
    (stoi((t).substr(0,2))*60+stoi((t).substr(3,2)))

int cal_cost(int time)
{
    int ret,t;

    ret = 10;
    t = max(time-100,0);
    
    return  (ret+=(t/50+((t%50==0)?0:1))*3);
}

bool    is_heavy_user(const User& a, const User& b)
{
    if (a.second != b.second) {
        return  a.second > b.second;
    }

    return  (a.first < b.first);
}

int input(void)
{
    cin>>n;

    for (int i=1;i<=n;i++) {
        string  time,name;

        cin>>time>>name;
        call[name] += get_minutes(time);
    }

    return  0;
}

int get_cost(void)
{
    map<string,int>::iterator   it;

    for (it=call.begin();it!=call.end();it++) {
        u.push_back({it->first,cal_cost(it->second)});
    }

    sort(u.begin(),u.end(),is_heavy_user);
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_cost();

    for (int i=0;i<u.size();i++) {
        cout<<u[i].first<<' '<<u[i].second<<'\n';
    }

    return  0;
}